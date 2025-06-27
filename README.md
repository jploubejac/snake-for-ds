# Snake for Nintendo DS 

Un petit **Snake** pour Nintendo DS, développé en C++ avec la librairie [libnds](https://devkitpro.org/wiki/libnds). C'est mon premier projet DS, donc il est assez basique, mais il fonctionne bien. Amuse-toi bien !

---

## Prérequis

- Linux (recommandé)
- [devkitPro](https://devkitpro.org/) (incluant devkitARM et libnds)
- `make`, `git`, `curl`

---

## Installation de la toolchain sur linux

### 1. Installer devkitPro

```bash
wget https://apt.devkitpro.org/install-devkitpro-pacman
chmod +x install-devkitpro-pacman
sudo ./install-devkitpro-pacman
```

### 2. Ajouter les variables d’environnement

Ajoute à la fin de ton `~/.bashrc` :

```bash
export DEVKITPRO=/opt/devkitpro
export DEVKITARM=$DEVKITPRO/devkitARM
export PATH=$PATH:$DEVKITARM/bin
```

Recharge ton terminal ou exécute :

```bash
source ~/.bashrc
```

### 3. Installer les outils DS

```bash
sudo dkp-pacman -S nds-dev
```

---

## Compilation du projet

Dans le dossier racine du projet, lance :

```bash
make
```

Le fichier `snake-for-ds.nds` sera généré à la racine.

Pour tout nettoyer, utilise :

```bash
make clean
```

---

## Fonctionnalités

- Contrôle via les boutons de la Nintendo DS
- Affichage sur les deux écrans
- Score en temps réel et meilleur score sauvegardé
- Gestion des collisions et fin de partie

---

## Lancer le jeu

1. Ouvre un émulateur DS (ex. [DeSmuME](https://desmume.org/)) ou ta console avec une flashcart.
2. Charge le fichier `snake-for-ds.nds`.

---

## Structure du projet

```
source/         # Code source C++
include/        # Headers
data/           # Graphiques convertis pour la DS
gfx/            # Images originales (PNG, etc.)
Makefile        # Script de compilation
README.md       # Ce fichier
```

