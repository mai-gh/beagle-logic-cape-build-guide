# beagle-logic-cape-build-guide

## TL;DR:

upload `beaglelogic_cape_v1-1-gerbers.zip` to https://dirtypcbs.com/store/pcbs




## The Dilemma:

I found out about this project a little late, but it seems like it could be very useful, even if some things are a bit outdated.

I need a logic analyzer and i found this: https://sigrok.org/wiki/BeagleLogic

there are a few problems though. the beaglebone blacks gpios are only 3.3v tolerant, so this "cape" was made to allowing analyzing 5v circuits.
this board is not sold anywhere. ok so we can order a pcb and the components and buid it right? well finding gerbers to send to a pcb fabricator was tricky, they are not in the beagle logic repository. https://github.com/abhishek-kakkar/BeagleLogic (commit f9dab91ac01472fdafd758277ec8a4526c6267f5) (Jul 5, 2020)

however there is kicad design files which can be used to generate new gerbers. I described my process of how generated the gerbers with kicad 5.1.10-4 in [KiCad-Gerber-DirtyPCBs.md](https://github.com/mai-gh/beagle-logic-cape-build-guide/blob/main/KiCad-Gerber-DirtyPCBs.md)


## Components:

info comes from here: https://docs.google.com/spreadsheets/d/12azxrOXTphC75ShBOmVUEJG1oJav0N1jhAYYi9JiIA4/edit#gid=0

|Reference|Type                                                     |Qty|DigiKey|Mouser|Extra|
|---------|---------------------------------------------------------|---|-------|------|-----|
|C1       |1uF 0603 X7R                                             |1  |[490-10734-1-ND](https://www.digikey.com/en/products/result?keywords=490-10734-1-ND)   |81-GRM188R71C105KE5D           |
|C2       |0.1uF 0603                                               |1  |[490-1524-1-ND](https://www.digikey.com/en/products/result?keywords=490-1524-1-ND)    |81-GRM39X104K25                |
|U1       |BeagleBone Stackable Cape Headers                        |2  |[1528-1365-ND](https://www.digikey.com/en/products/result?keywords=1528-1365-ND) || https://www.adafruit.com/products/706|
|U2       |SN74LVCH16T245DGGR                                       |1  |[296-19568-1-ND](https://www.digikey.com/en/products/result?keywords=296-19568-1-ND)   |595-SN74LVCH16T245GR           |
|P1       |14x2 (28pin) right angled 2.54mm male pin strip          |1  |[S2112EC-14-ND](https://www.digikey.com/en/products/result?keywords=S2112EC-14-ND)    |(suggest alternative part here)|
|Q1       |BSS138                                                   |1  |[BSS138CT-ND](https://www.digikey.com/en/products/result?keywords=BSS138CT-ND) |9845330                        |
|R1       |0603, 100K                                               |1  |[311-100KHRCT-ND](https://www.digikey.com/en/products/result?keywords=311-100KHRCT-ND)  |603-RC0603FR-07100KL           |
|R14      |0603, 1K                                                 |1  |[311-1.00KHRCT-ND](https://www.digikey.com/en/products/result?keywords=311-1.00KHRCT-ND) |603-RC0603FR-071KL             |
|R15      |0402, 0R (solder bridge in practice)                     |0  |[311-0.0JRCT-ND](https://www.digikey.com/en/products/result?keywords=311-0.0JRCT-ND)   |603-RC0402JR-070RL             |
|R8       |0603, 0R (not populated unless 14 channels are required) |0  |[311-0.0HRCT-ND](https://www.digikey.com/en/products/result?keywords=311-0.0HRCT-ND)   |603-RC0603FR-070RL             |
|R9       |0603, 0R (not populated unless 14 channels are required)  





## Cheaper Sources:

this table is for the cheapest prices to build 10 capes

|Ref|Link|Order Qty|
|---|----|---------|
|C1 | https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_Taiyo-Yuden-EMK107B7105KA-T_C92759.html | 50  |
|C2 | https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_CCTC-TCC0603X7R104K500CT_C282519.html   | 100 |
|U1 | https://www.aliexpress.com/item/3256803448359946.html                                                              | 2X20P 20PCS & 2X3P 20PCS |
|U2 | https://lcsc.com/product-detail/Receivers-Transceivers_Texas-Instruments-SN74LVCH16T245DGGR_C352975.html           | 10  |
|P1 | https://lcsc.com/product-detail/Pin-Headers_HCTL-PZ254-2-14-W-8-5_C2894994.html                                    | 10  |
|Q1 | https://lcsc.com/product-detail/MOSFETs_UMW-Youtai-Semiconductor-Co-Ltd-BSS138_C347484.html                        | 10  |
|R1 | https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_Walsin-Tech-Corp-WR06X1003FTL_C132374.html             | 100 | 
|R14| https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_YAGEO-RC0603FR-071KL_C22548.html                       | 100 |

### Total Costs:

( includes shipping )

|Site|Description|Price|
|----|-----------|-----|
|dirtypcbs | 10x pcbs               | $31.95 |
|aliexpress| stackable cape headers | $13.52 |
|lcsc      | all other components   | $22.98 |

**Total: $68.45**


