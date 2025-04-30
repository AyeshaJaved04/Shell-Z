read -p "→ Enter the MERN project root folder name: " project_root

if [ -z "$project_root" ]; then
  echo "❌ Project name cannot be empty."
  exit 1
fi

mkdir "$project_root"
cd "$project_root" || exit

### Frontend Setup ###
echo " "
echo -e "\033[1;32m🔧 Setting up React frontend using Vite...\033[0m"
read -p "→ Enter the frontend folder name (default: client): " client_folder
client_folder=${client_folder:-client}

npm create vite@latest "$client_folder" -- --template react

if [ $? -ne 0 ]; then
  echo "❌ Failed to create React frontend."
  exit 1
fi

cd "$client_folder" || exit

read -p "→ Do you want to install common frontend dependencies (react-router-dom, axios)? (y/n): " INSTALL_COMMON_FRONTEND
if [[ "$INSTALL_COMMON_FRONTEND" =~ ^[yY]$ ]]; then
  npm install react-router-dom axios
  echo "✅ Installed react-router-dom and axios."
fi

read -p "→ Install additional frontend dependencies? (y/n): " INSTALL_EXTRA_FE
if [[ "$INSTALL_EXTRA_FE" =~ ^[yY]$ ]]; then
  read -p "→ Enter additional frontend dependencies (space-separated): " extra_deps_fe
  [ -n "$extra_deps_fe" ] && npm install $extra_deps_fe
fi

cd ..

### Backend Setup ###
echo " "
echo -e "\033[1;32m🔧 Setting up Node.js + Express backend...\033[0m"
read -p "→ Enter the backend folder name (default: server): " server_folder
server_folder=${server_folder:-server}

mkdir "$server_folder"
cd "$server_folder" || exit
npm init -y > /dev/null

npm install express mongoose dotenv cors

mkdir -p src/{models,controllers,routes,middleware,utils,database}
touch src/index.js src/constants.js .env .gitignore

echo 'node_modules/' > .gitignore

echo 'PORT=5000
MONGO_URI=mongodb://localhost:27017/mydatabase' > .env

cat <<EOL > src/index.js
const express = require('express');
const mongoose = require('mongoose');
const cors = require('cors');
require('dotenv').config();

const app = express();
app.use(cors());
app.use(express.json());

const PORT = process.env.PORT || 5000;
const MONGO_URI = process.env.MONGO_URI;

mongoose.connect(MONGO_URI, { useNewUrlParser: true, useUnifiedTopology: true })
  .then(() => console.log('✅ MongoDB connected'))
  .catch(err => console.error('❌ MongoDB connection error:', err));

app.get('/', (req, res) => res.send('Hello from backend!'));

app.listen(PORT, () => {
  console.log(\`🚀 Server running on port \${PORT}\`);
});
EOL

echo "module.exports = {
  SAMPLE_CONSTANT: 'sample_value'
};" > src/constants.js

read -p "→ Install additional backend dependencies? (y/n): " INSTALL_EXTRA_BE
if [[ "$INSTALL_EXTRA_BE" =~ ^[yY]$ ]]; then
  read -p "→ Enter additional backend dependencies (space-separated): " extra_deps_be
  [ -n "$extra_deps_be" ] && npm install $extra_deps_be
fi

cd ..

echo ""
echo " "

echo "✅ MERN stack project '$project_root' initialized!"