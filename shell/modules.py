import sys
import time
import re
import os
import requests
import json
import anthropic
from openai import OpenAI
from dotenv import load_dotenv

load_dotenv()

def clean_response(text):
    """Replaces single * with • for bullet points and removes ** for markdown headings."""
    text = re.sub(r"(?<!\*)\*(?!\*)", "•", text)  # Replace single * with bullet points
    text = re.sub(r"\*\*(.*?)\*\*", r"\1", text)  # Remove ** for headings
    return text.strip()

def typewriter_effect(text, delay=0.02):
    """Prints text character by character with a delay for a typing effect."""
    for char in text:
        sys.stdout.write(char)
        sys.stdout.flush()
        time.sleep(delay)
    print()
    
def model_router(model_name, query):
    model_name = model_name.lower()
    if model_name == "gemini":
        return ask_gemini(query)
    elif model_name == "deepseek":
        return ask_deepseek(query)
    elif model_name == "gpt":
        return ask_chatGPT(query)
    elif model_name == "perplexity":
        return ask_perplexity(query)
    elif model_name == "claude":
        return ask_claude_sonnet(query)
    else:
        return f"Shell-Z doesn't support: {model_name}"

def ask_gemini(query):
    headers = {
        "Content-Type": "application/json"
    }
    data = {
        "contents": [
            {
                "parts": [
                    {"text": query}
                ]
            }
        ]
    }

    GEMINI_KEY = os.getenv("GEMINI_API_KEY")
    URL = os.getenv("GEMINI_URL")

    GEMINI_URL = URL + GEMINI_KEY
    response = requests.post(GEMINI_URL, headers=headers, data=json.dumps(data))

    if response.status_code == 200:
        result = response.json()
        
        try:
            if "candidates" in result and "content" in result["candidates"][0]:
                parts = result["candidates"][0]["content"].get("parts", [])
                ai_text = "\n".join(part["text"] for part in parts if "text" in part)
                return ai_text
        except (KeyError, IndexError, TypeError) as e:
            return f"Error extracting response: {str(e)}"

    return f"Error: {response.status_code} - {response.text}"


def ask_chatGPT(query):
    API_KEY = os.getenv("OPENAI_API_KEY")  # Replace with your actual API key
    OPENAI_URL = os.getenv("OPENAI_URL")

    headers = {
        "Authorization": f"Bearer {API_KEY}",
        "Content-Type": "application/json"
    }

    data = {
        "model": "gpt-3.5-turbo",  # or "gpt-4" if you have access
        "messages": [{"role": "user", "content": query}],
        "temperature": 0.7
    }

    try:
        response = requests.post(OPENAI_URL, headers=headers, json=data)
        response.raise_for_status()  # Raises HTTPError for bad responses (4xx or 5xx)

        result = response.json()
        return result["choices"][0]["message"]["content"]

    except requests.exceptions.HTTPError as http_err:
        return f"HTTP error occurred: {http_err} - {response.text}"
    except requests.exceptions.RequestException as req_err:
        return f"Request error occurred: {req_err}"
    except (KeyError, IndexError, TypeError) as parse_err:
        return f"Error parsing response: {parse_err}"



def ask_deepseek(query):
    client = OpenAI(api_key=os.getenv("DEEPSEEK_API_KEY"), base_url=os.getenv("DEEPSEEK_URL"))

    response = client.chat.completions.create(
        model="deepseek-chat",
        messages=[
            {"role": "system", "content": "You are a helpful assistant"},
            {"role": "user", "content": "Hello"},
        ],
        stream=False
    )
    print(response.choices[0].message.content)
        
def ask_perplexity(query):
    headers = {
        "Authorization": f"Bearer {os.getenv('PERPLEXITY_API_KEY')}",
        "Content-Type": "application/json"
    }

    payload = {
        "model": "sonar",
        "messages": [
            {
                "role": "system",
                "content": "Be precise and concise."
            },
            {
                "role": "user",
                "content": query
            }
        ]
    }

    try:
        response = requests.post("https://api.perplexity.ai/chat/completions", headers=headers, json=payload)
        response.raise_for_status()
        result = response.json()
        return result["choices"][0]["message"]["content"]
    except requests.exceptions.RequestException as err:
        return f"Perplexity API error: {err}"
    except (KeyError, IndexError, TypeError) as parse_err:
        return f"Perplexity parsing error: {parse_err}"


def ask_claude_sonnet(query):
    client = anthropic.Anthropic(api_key=os.getenv("CLAUDE_API_KEY"))

    try:
        message = client.messages.create(
            model="claude-3-sonnet-20240229",
            max_tokens=1024,
            temperature=0.7,
            system="You are a helpful assistant for Shell-Z.",
            messages=[
                {
                    "role": "user",
                    "content": [
                        {"type": "text", "text": query}
                    ]
                }
            ]
        )

        return "\n".join(block.text for block in message.content if block.type == "text")

    except Exception as e:
        return f"Claude API error: {str(e)}"