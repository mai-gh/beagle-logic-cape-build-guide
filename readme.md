# beagle-logic-cape-build-guide

## TL;DR:

upload `beaglelogic_cape_v1-1-gerbers.zip` to https://dirtypcbs.com/store/pcbs




## The Dilemma:

I found out about this project a little late, but it seems like it could be very useful, even if some things are a bit outdated.

I need a logic analyzer and i found this:

https://sigrok.org/wiki/BeagleLogic

there is a few problems though. the beaglebone blacks gpios are only 3.3v tolerant, so this "cape" was made to allowing analyzing 5v circuits.
this board is not sold anywhere. ok so we can order a pcb and the components and buid it right? well finding gerbers to send to a pcb fabricator was tricky, they are not in the beagle logic repository. https://github.com/abhishek-kakkar/BeagleLogic (commit f9dab91ac01472fdafd758277ec8a4526c6267f5) (Jul 5, 2020)

however there is kicad design files which can be used to generate new gerbers.

this is also tricky as there are lots of options to choose from when exporting a pcb design as a gerber. the fabricator I chose was dirtypcbs.com and i found a guide for creating gerbers with the correct settings for this fab. https://github.com/VojislavM/KiCad-Gerber-Wiki 

so this guide was written for an earlier version of kicad than i have and at this moment only kicad v6 is available in the archlinux repositories, so lets track down the PKGBUILD for kicad5 and build it: https://github.com/archlinux/svntogit-community/commits/packages/kicad/trunk

I have included the PKGBUILD for the version i was able to compile, though it still doesnt exactly fit the instructions. so i included my own modified instructions if for nothing else than to remember what i did.

## Components:

info comes from here: https://docs.google.com/spreadsheets/d/12azxrOXTphC75ShBOmVUEJG1oJav0N1jhAYYi9JiIA4/edit#gid=0

|Reference|Type                                                                                                               |Qty|DigiKey reference|Mouser Reference               |
|---------|-------------------------------------------------------------------------------------------------------------------|---|-----------------|-------------------------------|
|C1       |1uF 0603 X7R                                                                                                       |1  |490-10734-1-ND   |81-GRM188R71C105KE5D           |
|C2       |0.1uF 0603                                                                                                         |1  |490-1524-1-ND    |81-GRM39X104K25                |
|U1       |BeagleBone Cape Headers, BSSQ-123-D-06-F-LF from Major League Electronics or https://www.adafruit.com/products/706 |2  |                 |                               |
|U2       |SN74LVCH16T245DGGR                                                                                                 |1  |296-19568-1-ND   |595-SN74LVCH16T245GR           |
|P1       |14x2 (28pin) right angled 2.54mm male pin strip                                                                    |1  |S2112EC-14-ND    |(suggest alternative part here)|
|Q1       |BSS138                                                                                                             |1  |BSS138CT-ND      |9845330                        |
|R1       |0603, 100K                                                                                                         |1  |311-100KHRCT-ND  |603-RC0603FR-07100KL           |
|R14      |0603, 1K                                                                                                           |1  |311-1.00KHRCT-ND |603-RC0603FR-071KL             |
|R15      |0402, 0R (solder bridge in practice)                                                                               |1  |311-0.0JRCT-ND   |603-RC0402JR-070RL             |
|R8       |0603, 0R (not populated unless 14 channels are required)                                                           |   |311-0.0HRCT-ND   |603-RC0603FR-070RL             |
|R9       |0603, 0R (not populated unless 14 channels are required)  
