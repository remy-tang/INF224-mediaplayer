# Projet INF224 (C++/Java Swing)
## Auteur : Remy Tang
### Projet implémenté sur VSCode et Eclipse sur Windows.
### Test effectué sur une machine de l'école sans problème.

In this project, we create a media player in C++ that is able to open and play files, and link it with a GUI written using Java Swing.

## C++

Q1. OK: On voit affiché "Hello brave new world" sur la console.

Q2&3. OK: on arrive à voir les attributs de l'objet.

Q4. Impossible de créer un objet MediaObject :
function "MediaObject::play" is a pure virtual function
car nous avons déclaré :
virtual void play() const = 0;

C'est normal, et c'est bien le comportement attendu.

Q5. Nous utilisons ici le polymorphisme caractéristique de l'orienté objet.
Cela est possible en particulier car nous avons déclaré la méthode showAttributes comme virtual dans MediaObject, et que nous l'avons redéfinie dans les sous-classes Photo et Vidéo.
Le tableau contient des pointeurs vers les objets pour utiliser leprincipe de liaison tardive : la méthode appelée est celle du pointé, pas du pointeur. 

Q6. Pour ne pas violer le principe d'encapsulation, nous faisons en sorte de ne retourner que des copies des chapitres d'un Film, au lieu d'un pointeur vers la variable d'instance du Film. Sans cela, un autre objet aurait accès à cette variable privée et pourrait la modifier.

Q7. On utilise des smartpointers pour nous faciliter la tache et détruire
automatiquement les objets créés avec new.
Pour assurer la copie et l'indépendance des listes de chapitres, il faudrait redéfinir l'opérateur de copie = et faire de la deep copy, c'est-à-dire ne copier que les champs des variables et non les pointeurs, sans quoi deux Films copiés partageront la même liste de chapitres.

Q8&9. On a ici une liste de pointeurs d'objets pour utiliser la propriété de liaison tardive. En Java, on n'a que des références vers les objets, qui sont comparables à des pointeurs.

Q10. Pour empêcher la création de classes avec new on peut rendre 'new' private et faire en sorte que MediaDatabase soit friend des classes multimédia.

Q11. Quelques fichiers multimédia sont mis à disposition pour les jouer ('Bird', 'Cat', 'Dog', 'Beach').

Les questions 12 et 13 (optionnelles) ne sont pas implémentées.

## Java Swing

Q1. Sans mettre JScrollPane, il est impossible de voir la partie du texte cachée par le redimensionnement.

Q2. Les boutons fonctionnent correctement.

Q3. Implémenté : boutons pour indiquer à l'utilisateur quels sont les fichiers multimédia disponibles, quels sont les groupes disponibles.
Il y a les boutons sur la barre d'outils pour chercher des informations sur les fichiers média et les groupes existants.
Enfin on peut jouer un fichier multimédia en cliquant sur 'Play Media' (essayer 'Dog' ou 'Cat').

Q4. OK ! Le makefile marche correctement. Le main est dans le fichier Client.java