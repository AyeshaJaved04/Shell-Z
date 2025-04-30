read -p "Enter GitHub username: " username

echo "Fetching GitHub profile for $username..."
echo "-----------------------------------------"
curl -s https://api.github.com/users/$username | jq '
{
  "Login": .login,
  "Name": .name,
  "Bio": .bio,
  "Public Repos": .public_repos,
  "Followers": .followers,
  "Following": .following,
  "Profile URL": .html_url
}'
