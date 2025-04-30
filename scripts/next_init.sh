#!/bin/bash

read -p "→ Enter the project name: " project_name

if [ -z "$project_name" ]; then
  echo "❌ Project name cannot be empty."
  exit 1
fi

# Create Next.js project using the latest template
npx create-next-app@latest "$project_name"

if [ $? -eq 0 ]; then
    echo " "
    echo "✅ Next.js project '$project_name' created successfully."

        cd "$project_name" || exit

        read -p "→ Do you want to install additional dependencies? (y/n): " INSTALL_EXTRA
        if [[ "$INSTALL_EXTRA" == "y" || "$INSTALL_EXTRA" == "Y" ]]; then
          read -p "→ Enter the additional dependencies (space-separated): " extra_deps
          if [ ! -z "$extra_deps" ]; then
            echo " "
            echo "𝌗 Installing: $extra_deps"
            npm install $extra_deps
            echo " "
            echo "✅ Additional dependencies installed."
          else
            echo "⚠️ No additional dependencies entered. Skipping..."
          fi
        fi

        echo "✅ Setup complete."
        echo "→ Starting the development server..."
        npm run dev
    else
        echo "⚠️ Skipped moving into project directory."
    fi
else
  echo "❌ Failed to create Next.js project."
fi
