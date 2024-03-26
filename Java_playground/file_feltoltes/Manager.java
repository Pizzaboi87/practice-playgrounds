/*
Hozd létre a Manager osztályt a ??. ábra alapján!
A konstruktor az imagesFolder adattagnak hozzon létre egy új Folder objektumot, mely
a paraméterként kapott mappában van és images a neve, az etcFolder-nek ugyanígy, etc
névvel.
A metódus hozzon létre egy új File objektumot a paraméterként kapott névvel és mérettel,
a képek mappájába, ha a fájlnév .jpg, .png vagy .gif végződésű, az egyebek mappájába
egyébként. A létrejött objektumra hívja meg a namer adattag rename metódusát. Írja ki az
alapértelmezett kimenetre az alábbi három szöveget idézőjelek nélkül:
"Stored {filename} at {fullPath}"
"Images size: {imagesSize} bytes"
"Etc size: {etcSize} bytes"
Ahol a kapcsos zárójelek közti értékek a megfelelő behelyettesítések és a kiírások végén sortörés
karakter szerepel. Térjen vissza a létrehozott és átnevezett File objektummal

- namer : Namer
- imagesFolder : Folder
- etcFolder : Folder

+ Manager(namer : Namer, rootFolder : Folder)
+ upload(fileName : String, size : long) : File
*/

public class Manager {
    private Namer namer;
    private Folder imagesFolder;
    private Folder etcFolder;

    public Manager(Namer namer, Folder rootFolder) {
        this.namer = namer;
        imagesFolder = new Folder(rootFolder, "images");
        etcFolder = new Folder(rootFolder, "etc");
    }

    public File upload(String fileName, long size) {
        Folder folder = fileName.endsWith(".jpg") || fileName.endsWith(".png") || fileName.endsWith(".gif") ? imagesFolder : etcFolder;
        File file = new File(folder, fileName, size);
        namer.rename(file);
        System.out.println("Stored " + fileName + " at " + file.fullPath());
        System.out.println("Images size: " + imagesFolder.size() + " bytes");
        System.out.println("Etc size: " + etcFolder.size() + " bytes");
        return file;
    }
}