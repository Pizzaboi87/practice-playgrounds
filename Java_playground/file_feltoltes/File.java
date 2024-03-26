/*
Készítsd el a File osztályt az ábra alapján!
Legyen egy háromparaméteres konstruktora, mely az ősosztály paraméterein kívül a saját adattagját is beállítja.
A megvalósított absztrakt metódus térjen vissza a megfelelő adattag értékével.

- size : long

+ File(parent : Folder, name: String, size: long)
*/

public class File extends FileSystemEntry {
    private long size;

    public File(Folder parent, String name, long size) {
        super(parent, name);
        this.size = size;
    }

    @Override
    public long size() {
        return size;
    }
}