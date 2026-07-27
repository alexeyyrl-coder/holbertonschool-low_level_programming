#!/bin/bash

cat > compile_all <<'EOC'
#!/bin/bash

FLAGS="-Wall -Werror -Wextra -pedantic -std=gnu89"

for file in *.c
do
 if [ -f "$file" ]; then
 output="${file%.c}.o"
 gcc $FLAGS -c "$file" -o "$output"
 fi
done
EOC

cat > all_good_thing <<'EOG'
#!/bin/bash

cd "$(dirname "$0")" || exit 1

chmod u+x compile_all all_good_thing over_craft 2>/dev/null

git add . ':!README.md' ':!*/README.md'

if git diff --cached --quiet; then
 echo "Nothing to commit"
else
 git commit -m "add all good thing"
 git push origin main
fi
EOG

cat > over_craft <<'EOO'
#!/bin/bash

touch \
main.h \
0-create_array.c \
1-strdup.c \
2-str_concat.c \
3-alloc_grid.c \
4-free_grid.c \
100-argstostr.c \
101-strtow.c
EOO

chmod u+x compile_all all_good_thing over_craft setup_tools.sh
