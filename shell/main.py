import sys
from modules import clean_response
from modules import typewriter_effect
from modules import model_router

if __name__ == "__main__":
    
    if len(sys.argv) < 3:
        print("Usage: python3 utils.py \"your prompt\" model_name")
        sys.exit(1)

    user_query = sys.argv[1]
    model_name = sys.argv[2].lower()

    raw_response = model_router(model_name, user_query)

    if "Shell-Z doesn't support" in raw_response:
        print(raw_response)
        sys.exit(1)


    cleaned_response = clean_response(raw_response)
    typewriter_effect(cleaned_response)