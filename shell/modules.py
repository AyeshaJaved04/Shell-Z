import sys
import time
import re
import os
import requests
import json
import anthropic
from openai import OpenAI
from dotenv import load_dotenv
from google import genai
from google.genai import types

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
    elif model_name == "grok":
        return ask_grok(query)
    else:
        return f"Shell-Z doesn't support: {model_name}"

def ask_gemini(query):
    client = genai.Client(
        api_key=os.environ.get("GEMINI_API_KEY"),
    )

    model = "gemini-2.5-pro"
    contents = [
        types.Content(
            role="user",
            parts=[
                types.Part.from_text(text=query),
            ],
        ),
    ]
    tools = [
        types.Tool(googleSearch=types.GoogleSearch(
        )),
    ]
    generate_content_config = types.GenerateContentConfig(
        thinking_config=types.ThinkingConfig(
            thinking_budget=-1,
        ),
        tools=tools,
        response_mime_type="text/plain",
    )

    try:
        response = client.models.generate_content(
            model=model,
            contents=contents,
            config=generate_content_config,
        )
        
        if response.candidates and response.candidates[0].content:
            parts = response.candidates[0].content.parts
            generated_text = "\n".join(part.text for part in parts if hasattr(part, 'text'))
            return generated_text
        return "Error: No valid response from Gemini"
        
    except Exception as e:
        return f"Error: {str(e)}"

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

def ask_chatGPT(query):
    """Interacts with the OpenAI GPT API."""
    try:
        api_key = os.getenv("OPENAI_API_KEY")
        if not api_key:
            return "Error: OPENAI_API_KEY not found in environment variables."

        client = OpenAI(api_key=api_key)
        response = client.chat.completions.create(
            model="gpt-4",
            messages=[
                {"role": "system", "content": "You are a helpful assistant."},
                {"role": "user", "content": query},
            ]
        )
        return response.choices[0].message.content
    except Exception as e:
        return f"ChatGPT API error: {str(e)}"

def ask_grok(query):
    """Interacts with the Grok API."""
    try:
        api_key = os.getenv("XAI_API_KEY")
        if not api_key:
            return "Error: XAI_API_KEY not found in environment variables."

        client = OpenAI(
            api_key=api_key,
            base_url="https://api.x.ai/v1",
        )
        response = client.chat.completions.create(
            model="grok-1",
            messages=[
                {"role": "system", "content": "You are a helpful assistant."},
                {"role": "user", "content": query},
            ],
            stream=False
        )
        return response.choices[0].message.content
    except Exception as e:
        return f"Grok API error: {str(e)}"

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