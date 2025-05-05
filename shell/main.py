import sys
from modules import clean_response
from modules import typewriter_effect
from modules import ask_gemini
from modules import ask_chatGPT
from modules import ask_deepseek
from modules import ask_perplexity
from modules import ask_claude_sonnet

if __name__ == "__main__":
    
    if len(sys.argv) < 3:
        print("Usage: python3 utils.py \"your prompt\" model_name")
        sys.exit(1)

    user_query = sys.argv[1]
    model_name = sys.argv[2].lower()

    if model_name == "gemini":
        raw_response = ask_gemini(user_query)
    elif model_name == "deepseek":
        raw_response = ask_deepseek(user_query)
    elif model_name == "gpt":
        raw_response = ask_chatGPT(user_query)
    elif model_name == "perplexity":
        raw_response = ask_perplexity(user_query)
    elif model_name == "claude":
        raw_response = ask_claude_sonnet(user_query)
    else:
        print(f"Shell-Z doesn't support: {model_name}")
        sys.exit(1)


    cleaned_response = clean_response(raw_response)
    typewriter_effect(cleaned_response)