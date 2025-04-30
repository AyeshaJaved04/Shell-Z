read -p "Enter GitHub username: " USERNAME
read -p "Enter Repository name: " REPO_NAME

URL="https://github.com/${USERNAME}/${REPO_NAME}"

git init

read -p "Do you want to add all files to staging? (y/n): " ADD_ALL
if [[ "$ADD_ALL" == "y" || "$ADD_ALL" == "Y" ]]; then
    git add .

    read -p "Do you want to remove any file from staging? (y/n): " REMOVE_FILES
    if [[ "$REMOVE_FILES" == "y" || "$REMOVE_FILES" == "Y" ]]; then
        echo "Currently staged files:"
        git diff --cached --name-only
        read -p "Enter filenames to unstage (separated by space): " FILES_TO_REMOVE
        git reset $FILES_TO_REMOVE
    fi
else
    read -p "Enter filenames to add (with extensions, separated by space): " FILES
    git add $FILES
fi

read -p "Enter your preferred commit message: " COMMIT_MSG
git commit -m "$COMMIT_MSG"

git branch -M main
git remote add origin "$URL"
git push -u origin main
