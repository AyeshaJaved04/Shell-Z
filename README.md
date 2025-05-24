<div align="center">
  <br />
    <a href="https://www.youtube.com/watch?v=43816Pa6y1k" target="_blank">
      <img src="https://github.com/user-attachments/assets/a5dc6393-05b8-4356-b417-3dcfcd96076d" alt="Project Banner">
      </a>
  <br />

  ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white) ![Python](https://img.shields.io/badge/python-3670A0?style=for-the-badge&logo=python&logoColor=ffdd54) ![Bash Script](https://img.shields.io/badge/bash_script-%23121011.svg?style=for-the-badge&logo=gnu-bash&logoColor=white) ![HTML5](https://img.shields.io/badge/html5-%23E34F26.svg?style=for-the-badge&logo=html5&logoColor=white) ![CSS3](https://img.shields.io/badge/css3-%231572B6.svg?style=for-the-badge&logo=css3&logoColor=white) ![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white)
 <!-- <br />
 [![LinkedIn](https://img.shields.io/badge/LinkedIn-%230077B5.svg?logo=linkedin&logoColor=white)](https://linkedin.com/in/krrishkumar) 
[![YouTube](https://img.shields.io/badge/YouTube-%23FF0000.svg?logo=YouTube&logoColor=white)](https://youtube.com/@codewithalphadotcom) -->
  <br />


# Shell-Z - Custom-Built AI Powered Terminal

A Custom-Built, AI-integrated terminal designed to enhance the command-line experience by combining modern development workflows, automation, and core operating system principles — all powered by a powerful command handler called __alpha__

</div>

## Features

- **Nexis** – A multithreaded __HTTP__ web server built from scratch, supporting concurrent client handling with thread-safe operations.
- **Sched-Zilla** – A process scheduling algorithm analyzer that uses multiprocessing to simulate realistic OS-level CPU scheduling (e.g. `FCFS, SJF, Round Robin`).
- **Automation Scripts** – Built-in shell scripts to automate routine development tasks like `Git setup, project scaffolding (React/Next.js), and GitHub interactions.`
- **alpha** – The intelligent command handler at the heart of Shell-Z that enables intuitive execution of all custom commands.
- **AI Model Integration** – Seamless integration with top AI models including `ChatGPT (OpenAI), Gemini (Google), Claude Sonnet (Anthropic), Perplexity, and DeepSeek.`
- **Unix Command Support** – Shell-Z supports standard Unix commands like `ls, cd, pwd, mkdir, rm, touch, top, ps, kill, and more` — all with smart error handling and beginner-friendly feedback to enhance the traditional command-line experience.

## Directory Structure
```bash
Shell-Z/
├── bin/                        # Compiled binaries
├── obj/                        # Object files
├── include/                    # Common header files
│   ├── shell.h
│   ├── utilities.h
│   ├── http_handler.h
│   ├── logger.h
│   ├── intro_modules.h
│   ├── custom_ui_modules.h
├── scheduler/                 # CPU Scheduling simulator module
│   ├── include/               # Scheduler-specific headers
│   │   ├── cpu_algorithms.h
│   ├── src/
│   │   ├── cpu_algorithms.c
│   │   ├── cpu_main.c
│   │   ├── fcfs.c
│   │   ├── sjf.c
│   │   ├── roundrobin.c
│   │   ├── main.c
│   ├── Makefile
├── server/                    # Multi-threaded HTTP server
│   ├── http_handler.c
│   ├── server.c
│   ├── logger.c
│   ├── Makefile
│   ├── obj/
│   ├── bin/
│   ├── logs/
│   ├── static/                # Static frontend content
│   │   ├── index.html
│   │   ├── style.css
│   │   ├── developers.html
│   │   ├── images/
│   │   ├── pages/
├── shell/                     # AI-integrated shell logic
│   ├── main.py
│   ├── modules.py
│   ├── shell.c
├── modules/                   # Custom UI and introductory C modules
│   ├── custom_ui_modules.c
│   ├── intro_modules.c
├── utilities/                 # Shared utility functions
│   ├── utilities.c
├── scripts/                   # Automation and setup scripts
│   ├── full_stack.sh
│   ├── git_clone_all.sh
│   ├── get_github_info.sh
│   ├── react_init.sh
│   ├── next_init.sh
│   ├── git_init.sh
├── main.c                     # Root entry point for Shell-Z
├── Makefile                   # Root-level Makefile
├── .gitignore
├── .env
```

## Installation & Setup

Follow the steps below to install and set up Shell-Z on your system.

__Prerequisites__

Before installing Shell-Z, make sure you have the following installed:

`OS:` UNIX-based platforms (macOS or Linux).

`Git:` To clone the repository.

`Python3:` Required for the AI model integration.

`pip3:` Python package manager to install dependencies.

`GCC:` Required for compiling C components.

`Make:` To automate Shell-Z build processes.

__Installation__
1. Clone the Repository

First, clone the Shell-Z repository to your local machine
```bash
git clone https://github.com/AyeshaJaved04/Shell-Z
```

2. Navigate to the project directory
```bash
cd Shell-Z
```

3. Build Shell-Z
```bash
make build || make
```

4. Run the Executable
```bash
./bin/main
```

## AI Integration
Shell-Z comes pre-configured to interact with multiple state-of-the-art AI models directly from your terminal via the alpha explain and alpha use commands. These integrations enable you to perform AI-powered tasks like code explanations, debugging, documentation help, and more — without leaving the command line.

__Supported AI Models__
`ChatGPT (OpenAI)` – Ideal for natural language understanding, technical explanations, and development support.
`Gemini (Google)` – Great for contextual assistance and problem-solving.
`Claude Sonnet (Anthropic)` – Known for its creative and language-focused responses.
`Perplexity AI` – Useful for search-style answers and summarization.
`DeepSeek` – Designed for code-heavy assistance and prompt engineering.

__To interact with AI models, create a .env file in root directory with the following variables and add your KEYS__
```bash
GEMINI_URL="https://generativelanguage.googleapis.com/v1beta/models/gemini-2.0-flash:generateContent?key="
GEMINI_API_KEY=""

OPENAI_URL="https://api.openai.com/v1/chat/completions"
OPENAI_API_KEY=""

DEEPSEEK_URL="https://api.deepseek.com"
DEEPSEEK_API_KEY=""

PERPLEXITY_URL="https://api.perplexity.ai/chat/completions"
PERPLEXITY_API_KEY=""

CLAUDE_API_KEY=""
```

__Key Commands__
| Command                      | Description                                                                   |
| ---------------------------- | ----------------------------------------------------------------------------- |
| `alpha list models`          | Lists all available AI models supported in Shell-Z                            |
| `alpha use <model-name>`     | Switch the active model to `<model-name>`                                     |
| `alpha current <model-name>` | Shows the currently active AI model                                           |
| `alpha explain <your-query>` | Sends the query to the selected model and displays the result in the terminal |

## Supported Commands

Though you can list all the available commands at runtime using:
```bash
alpha list -a
```
or
```bash
alpha list --all
```
to see everything Shell-Z supports, here's a full reference of commonly used commands for quick access.

__Common UNIX Commands__
| Command | Description |
|---------|------------|
| `pwd` | Display the current working directory |
| `ls` | List files and directories |
| `echo "Shell-Z!"` | Display the message "Shell-Z!" |
| `mkdir test` | Create a new directory named "test" |
| `touch temp.txt` | Create an empty file named "temp.txt" |

__Shell-Z Exclusives__
| Command | Description |
|---------|------------|
| `alpha list -a` | List all commands that Shell-Z supports |
| `alpha list models` | List all the AI models that Shell-Z supports |
| `rm oldfile.txt` | Remove the file "oldfile.txt" |
| `alpha help` | View the help board of Shell-Z |
| `alpha guide` | Get a quick guide menu of Shell-Z |
| `alpha clear` | Clears the terminal screen |
| `alpha who` | Get to know about alpha - The Custom Command Handler |
| `alpha start server 'or' alpha run dev` | Run the development server i.e. custom built multi-threaded http web server. |
| `alpha clean server` | Run make clean in server directory in Shell-Z and remove all the object files and binaries |
| `alpha show server details` | Show server details page on command line |
| `alpha add <path-to-your-directory>` | Serve your own custom pages on the server |
| `alpha run scheduler` | Run the process scheduling algorithms analyzer |
| `alpha clean scheduler` | Run make clean in scheduler directory in Shell-Z and remove all the object files and binaries |
| `alpha show scheduler details` | Show scheduler details page on command line |
| `alpha use <model-name>` | Choose the model for query resolution |
| `alpha current <model-name>` | Show current model in use |
| `alpha explain <your-query>` | Interact with AI models and resolve queries |
| `alpha git init` | Initialize a local git repository and connect with the cloud repository. |
| `alpha react init` | Initialize a React JS Project in prefered directory. |
| `alpha next init` | Initialize a Next JS Project in prefered directory. |
| `alpha clone all` | Clone all the repositories of a github profile. |
| `alpha fetch GitHub profile` | Fetch a Github user profile details. |
