# 33168-Capteur lumiere solaire GROVE

Capteur lumiere solaire GROVE [33168](https://www.pierron.fr/capteur-de-lumiere-solaire-grove.html)

<div style="text-align: justify">Ce capteur de lumière numérique, compatible Grove, est basé sur le composant SI1145. Il s'agit d'un capteur multicanal, capable de détecter la lumière UV, la lumière visible et la lumière infrarouge.
Ce module se raccorde sur un port I2C du Base Shield via un câble 4 conducteur.</div>
<br>

Caractéristiques techniques :
- Alimentation : 3.3 à 5 V
- Consommation : 3,5 mA
- Plage de mesure : 280 à 950 nm

![L-33168](/img/L-33168.jpg)

# Installation des fichiers dans IDE Arduino:
<div style="text-align: justify">Créer un nouveau répertoire nommé "Pierron..." dans le dossier "libraries" de votre dossier Arduino.
Y placer tous les fichiers.</div>
Ou
<div style="text-align: justify">télécharger le dépôt en ZIP et dans l'IDE Arduino : Croquis / inclure bibliothèque / ajouter la bibliothèque ZIP.</div>

<div style="text-align: justify">Pour utiliser la librairie dans votre propre projet, importez-la avec  Sketch > Import Library.</div>

# Usage :
Pour l’utilisation de ce module, référez-vous aux indications présentes sur le circuit imprimé GROVE.

![C-33168](/img/C-33168.jpg)

# Schémas :

![SCH-33168](/img/SCH-33168.jpg)
![BRD-33168](/img/BRD-33168.jpg)

# Complément sur la programmation :

![C1-33168](/img/C1-33168.jpg)

# RESSOURCES À TÉLÉCHARGER :

Ressource utilisation : [SI1145-46-47](https://github.com/pierron-asco-celda/33136-Emetteur_infrarouge_GROVE/blob/main/src/Datasheet_tsal6200.pdf)

# Exemple :
### Arduino / C++
```cpp
/*
    ** Mesure multicanal lumière visible,IR et UV sur une plage de 280 à 950 nm, module Grove **
       PIN I2C Module shield GROVE
       Moniteur série -> Baud rate 115200.
*/

#include <Wire.h>

#include "Arduino.h"
#include "SI114X.h"

SI114X SI1145 = SI114X();

void setup() {
  Serial.begin(115200);
  while (!SI1145.Begin()) {
    delay(2000);
  }
}

void loop() {
  Serial.print("Lumière visible : ");
  Serial.println(SI1145.ReadVisible());
  Serial.print("Lumière IR : ");
  Serial.println(SI1145.ReadIR());
  Serial.print("Lumière UV : ");
  Serial.println((float)SI1145.ReadUV() / 100);
  Serial.println("--------------------------------------");
  delay(1000);
}
```
## À propos :
<br>
PIERRON ASCO-CELDA (https://www.pierron.fr).