# KiCad-Gerber-DirtyPCBs

### Original Document: https://github.com/VojislavM/KiCad-Gerber-Wiki

In this guide I will be using `kicad 5.1.10-4`


Documentation how to generate Gerber files from KiCad for PCB manufacturing at [dirtypcbs][DIRTY_PCB_LINK]. 

On this link, you can find all information about [dirtypcbs info][DIRTY_PCB_ABOUT_LINK] PCB manufacturing. 

There are several things need to be done before sending files to manufacture PCBs. Files are generated with KiCad EDA tool, and these are the steps to send your files to [dirtypcbs][DIRTY_PCB_LINK] and get your boards as you want.

When board file is finished:

1. Set the origin: Go to **Place** -> **Drill and Place offset** and then set the origin near the bottom left corner of the board. for this project i set the grid size to 1.0mm and chose:
- x: 114
- y: 130

![](https://raw.githubusercontent.com/mai-gh/beagle-logic-cape-build-guide/master/pictures/01_select_corner.png)

2. Generate Gerber files PDF: Go to **File** -> **Plot**. New Window will appear, like in picture 1.

make sure the following layers are selected:
- F.Cu
- B.Cu
- F.SilkS
- B.SilkS
- F.Mask
- B.Mask
- Edge.Cuts

 Click on **Plot** and it will generate Gerber files in PDF form so they could be checked. 

![](https://raw.githubusercontent.com/mai-gh/beagle-logic-cape-build-guide/master/pictures/02_plot_pdf.png)
![](https://raw.githubusercontent.com/mai-gh/beagle-logic-cape-build-guide/master/pictures/03_refill.png)

3. Generate Gerber files: In the same window click change the **Plot format** from PDF to **Gerber**, a window will change and it will look like in picture 2. Some additional boxes need to be checked and everything should be like in picture 2. Then click on **Plot** and Gerber files will be generated.

![](https://raw.githubusercontent.com/mai-gh/beagle-logic-cape-build-guide/master/pictures/04_plot_gerber.png)

4. Generate Drill File: Next click on the **Generate Drill File** and the new window will appear, like in picture 3. Again everything should be like in picture 3. When everything is set click on **Drill File**, and Drill file will be generated. 
  
![](https://raw.githubusercontent.com/mai-gh/beagle-logic-cape-build-guide/master/pictures/05_drill_files.png)
  **Note:** If there are plated and non plated holes in the design please check the "Merge PTH and NPTH holes into one file"

5. Change extensions: Extensions of files that contains Edge of the board and Drills needs to be changed. Go to project folder, than go to folder **/Gerber** and change extensions for Drill file from **.drl** to **.txt** and Edge (keepout) file from **.gm1** to **.gko**.

```
cd cape/trial
mkdir out
cp 'BeagleLogic Cape-F_SilkS.gto'    out/BeagleLogic_Cape-F_SilkS.gto
cp 'BeagleLogic Cape-F_Mask.gts'     out/BeagleLogic_Cape-F_Mask.gts
cp 'BeagleLogic Cape-F_Cu.gtl'       out/BeagleLogic_Cape-F_Cu.gtl
cp 'BeagleLogic Cape-B_Cu.gbl'       out/BeagleLogic_Cape-B_Cu.gbl
cp 'BeagleLogic Cape-B_Mask.gbs'     out/BeagleLogic_Cape-B_Mask.gbs
cp 'BeagleLogic Cape-B_SilkS.gbo'    out/BeagleLogic_Cape-B_SilkS.gbo
cp 'BeagleLogic Cape-Edge_Cuts.gm1'  out/BeagleLogic_Cape-Edge_Cuts.gko
cp 'BeagleLogic Cape.drl'            out/BeagleLogic_Cape-Drill.txt
cd out
zip beaglelogic_cape_v1-1-gerbers.zip *
```

After that everything is ready, just check your Gerber files in Gerber viewer and send them to manufacturing.

![](https://raw.githubusercontent.com/mai-gh/beagle-logic-cape-build-guide/master/pictures/06_order.png)

**cross your finger and wait**



[//]: # (These are reference links used in the body)
[DIRTY_PCB_LINK]:<https://dirtypcbs.com/>
[DIRTY_PCB_ABOUT_LINK]:<https://dirtypcbs.com/store/pcbs/about>
