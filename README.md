# RAY v2.0

## Présentation du projet

Ce fichier est la base de code de RAY v2.0, un robot conçu pour participer à une compétition de football robotique. L'objectif de la compétition est que les robots marquent le plus de buts possible lors d'un match en étant contrôlés à distance.

Ce projet utilise l'**IDE Arduino** et un **microcontrôleur ESP32** pour implémenter la logique de contrôle du robot. Le code gère l'interaction avec les différents composants matériels permettant au robot de se déplacer, et de communiquer avec un contrôleur.

# Résultats exceptionnels de la compétition

🏆 **L'année dernière**, j'ai eu le plaisir de remporter la compétition avec la version **RAY v1.0**, et cette année 2024, avec la version **RAY v2.0**, **j'ai de nouveau triomphé** et gagné la compétition ! 🏆

Une victoire bien méritée grâce à l'amélioration continue du robot !

## Fonctionnalités

- Contrôle du mouvement du robot via un contrôleur PS3 en Bluetooth.
- Logique de contrôle efficace pour la navigation sur le terrain et la détection des buts.
- Code modulaire et facilement adaptable pour de futures améliorations ou personnalisations.

## Outils et Technologies

- **IDE Arduino** : Utilisé pour écrire, compiler et télécharger le code.
- **Microcontrôleur ESP32** : Sert de cerveau au robot, gérant les entrées et sorties.
- **Communication Bluetooth** : Pour le contrôle à distance via un contrôleur PS3.
- **Matériel** : Moteurs et contrôleurs de moteurs (driver) pour le mouvement.

## Installation

### Prérequis

Pour utiliser ou modifier ce projet, vous aurez besoin de :

1. **IDE Arduino** installé sur votre ordinateur.
2. **Gestionnaire de cartes ESP32** configuré dans l'IDE Arduino. Suivez [ce guide](https://randomnerdtutorials.com/installing-esp32-arduino-ide-2-0/) pour l'installation.
3. Les bibliothèques nécessaires installées dans l'IDE Arduino :
   - `Ps3Controller` (pour la communication avec le contrôleur PS3).

### Installation

1. Clonez ce dépôt sur votre machine locale :
   ```bash
   git clone https://github.com/kalboussiKarim/RAY-v2.0-Robot-source-code.git  
   ```
2. **N'oubliez pas de modifier le contenu du fichier `secrets.h` avec l'adresse MAC de votre propre contrôleur PS3.**  
   Vous pouvez utiliser un outil comme **SixaxisPairTool** pour trouver l'adresse MAC de votre contrôleur.

## Contact

Si vous souhaitez obtenir le schéma du circuit de ce robot, vous pouvez me contacter par email à :  
**kalboussikarim3@gmail.com**
