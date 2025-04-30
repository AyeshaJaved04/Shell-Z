read -p "→ Enter GitHub username: " GH_USER

mkdir -p "$GH_USER"
cd "$GH_USER" || exit

repos=$(curl -s "https://api.github.com/users/$GH_USER/repos?per_page=100" | jq -r '.[].clone_url')

for repo in $repos; do
    echo "→ Cloning repository: $repo"
    echo " "
    git clone "$repo"
    echo " "
    echo -e "\033[32m→ Github Repository '$repo' cloned successfully...\033[0m"

    echo " "
done
echo " "
echo "✅ All repositories from $GH_USER have been cloned."