# beagle-logic-cape-build-guide

I found out about this project a little late, but it seems like it could be very useful, even if some things are a bit outdated.

## The Dilemma:

I need a logic analyzer and i found this:

https://sigrok.org/wiki/BeagleLogic

there is a few problems though. the beaglebone blacks gpios are only 3.3v tolerant, so this "cape" was made to allowing analyzing 5v circuits.
this board is not sold anywhere. ok so we can order a pcb and the components and buid it right? well finding gerbers to send to a pcb fabricator was tricky, they are in the beagle logic repository. https://github.com/abhishek-kakkar/BeagleLogic (commit f9dab91ac01472fdafd758277ec8a4526c6267f5) (Jul 5, 2020)

there is however the kicad design files which can be used to generate new gerbers.

this is also tricky as there are lots of options to choose from when exporting a pcb design as a gerber. the fabricator I chose was dirtypcbs.com and i found a guide for creating gerbers with the correct settings for this fab. https://github.com/VojislavM/KiCad-Gerber-Wiki 

so this guide was written for kicad v5 and at this moment only kicad v6 is available in the archlinux repositories, so lets track down the PKGBUILD for kicad5 and build it: https://github.com/archlinux/svntogit-community/commits/packages/kicad/trunk


