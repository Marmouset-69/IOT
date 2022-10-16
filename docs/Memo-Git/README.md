# Memo-Git

## Mardown
https://docs.github.com/en/github/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax

## Commandes de base

### Initialiser un projet
```cd chemin/vers/mon_dossier
echo "# MON_PROJET" >> README.md
git init
git add README.md
git commit -m "Initial commit"
```

### Récuperer le repo sur Github
`git clone *<mon-projet>*.git chemin/vers/mon_dossier`

### Status des fichiers
*La commande git status vous montrera les différents états des fichiers de votre répertoire de travail et de l’index. Quels sont les fichiers modifiés et non indexés et lesquels sont indexés mais pas encore validés. *

```git status```

### Git add
*La commande git add ajoute le contenu du répertoire de travail dans la zone d’index pour le prochain commit.*

`git add .` pour tout ajouter sinon `git add README.md`

### commit
*La commande git commit prend tout le contenu des fichiers qui ont été indexés avec git add et enregistre un nouvel instantané permanent dans la base de données puis fait pointer la branche courante dessus.*

#### Premier commit
```git add .
git commit -m "initial commit"
```
#### Commit suivant
```git add toto.md
git commit -m "message du commit"
```

### Envoyer ses commits vers le dépôt distant
*La commande git push est utilisée pour communiquer avec un autre dépôt, calculer ce que votre base de données locale a et que le dépôt distant n’a pas, et ensuite pousser la différence dans l’autre dépôt. *

```git push```

### Mettre à jour le dépôt local
*Git ira chercher les modifications depuis le dépôt distant que vous spécifiez et essaie immédiatement de les fusionner dans la branche dans laquelle vous vous trouvez.*

```git pull```

### git rm
*La commande git rm est utilisée pour supprimer des fichiers de l’index et du répertoire de travail pour Git*

```git rm```

### git mv

*La commande git mv est une commande de faible utilité pour renommer un fichier et ensuite lancer git add sur le nouveau fichier et git rm sur l’ancien.*

```git mv```

## git log
```git log```
