
#!/bin/bash

# =====================================
# OVERCRAFT
# =====================================

# Quitter le programme
quit() {
    echo "Arrêt de overcraft."
    exit 0
}

# Demander l'extension
ask_extension() {
    while true; do
        read -e -r -p "Extension (.c, .py, .cpp...) [vide = aucune] : " extension || quit

        [[ "$extension" == ":wq" ]] && quit

        # Retirer le point initial
        extension="${extension#.}"

        if [[ -z "$extension" || "$extension" =~ ^[a-zA-Z0-9]+$ ]]; then
            return
        fi

        echo "Erreur : extension invalide."
    done
}

# Créer un fichier
create_file() {
    local number="$1"
    local name="$2"
    local file="${number}-${name}"

    # Vérifier le nom
    if [[ -z "$name" || "$name" == *"/"* || "$name" == "." || "$name" == ".." ]]; then
        echo "Ignoré : nom invalide [$name]"
        return 1
    fi

    # Ajouter l'extension si nécessaire
    if [[ -n "$extension" ]]; then
        file="${file}.${extension}"
    fi

    # Vérifier si le fichier existe
    if [[ -e "$file" || -L "$file" ]]; then
        echo "Ignoré : $file existe déjà."
        return 1
    fi

    # Créer le fichier
    if touch -- "$file"; then
        echo "Créé : $file"
        return 0
    else
        echo "Erreur : impossible de créer $file"
        return 1
    fi
}

# =====================================
# MODE MANUEL
# =====================================

manual_mode() {
    local max="$1"
    local i=0
    local filename

    ask_extension

    echo ""
    echo "Entre un nom pour chaque fichier."
    echo "Tape :wq pour quitter."
    echo ""

    # Commencer à 0 et terminer au nombre inclus
    while ((i <= max)); do

        read -e -r -p "Nom du fichier $i : " filename || quit

        [[ "$filename" == ":wq" ]] && quit

        if [[ -z "$filename" ]]; then
            echo "Erreur : nom vide."
            continue
        fi

        if create_file "$i" "$filename"; then
            ((i+=1))
        else
            echo "Réessaie pour le fichier $i."
        fi
    done
}

# =====================================
# MODE FICHIER
# =====================================

file_mode() {
    local source="$1"
    local i=0
    local created=0
    local word
    local -a words

    # Vérifier le fichier source
    if [[ ! -f "$source" || ! -r "$source" ]]; then
        echo "Erreur : fichier introuvable ou illisible : $source"
        return 1
    fi

    # Lire tous les mots du fichier
    # Séparateurs : espace, tabulation, retour à la ligne
    mapfile -t words < <(
        awk '{for (j=1; j<=NF; j++) print $j}' "$source"
    )

    echo ""
    echo "Fichier source : $source"
    echo "Mots détectés : ${#words[@]}"
    echo ""

    if (( ${#words[@]} == 0 )); then
        echo "Erreur : le fichier ne contient aucun mot."
        return 1
    fi

    ask_extension

    echo ""
    echo "Création des fichiers..."
    echo ""

    # Parcourir tous les mots du tableau
    for word in "${words[@]}"; do

        if create_file "$i" "$word"; then
            ((created+=1))
        fi

        ((i+=1))
    done

    echo ""
    echo "----------------------------"
    echo "Mots traités : $i"
    echo "Fichiers créés : $created"
    echo "----------------------------"
}

# =====================================
# LISTE DES FICHIERS
# =====================================

list_files() {
    echo ""
    echo "Fichiers disponibles :"
    echo "----------------------------"

    find . -maxdepth 1 -type f -printf '%f\n' | sort

    echo "----------------------------"
    echo ""
}

# =====================================
# PROGRAMME PRINCIPAL
# =====================================

echo "================================"
echo "          OVERCRAFT"
echo "================================"
echo ""
echo "Nombre : création manuelle"
echo "Fichier : création automatique"
echo ":rw     : afficher les fichiers"
echo ":wq     : quitter"
echo ""

while true; do

    read -e -r -p "Nombre ou fichier source : " choice || quit

    case "$choice" in

        ":wq")
            quit
            ;;

        ":rw")
            list_files

            read -e -r -p "Nom du fichier source : " source || quit

            [[ "$source" == ":wq" ]] && quit

            if file_mode "$source"; then
                break
            fi
            ;;

        *)
            if [[ "$choice" =~ ^[0-9]+$ ]]; then

                manual_mode "$((10#$choice))"
                break

            elif [[ -f "$choice" ]]; then

                if file_mode "$choice"; then
                    break
                fi

            else
                echo "Erreur : nombre ou fichier invalide."
            fi
            ;;
    esac

done

echo ""
echo "Opération terminée."
