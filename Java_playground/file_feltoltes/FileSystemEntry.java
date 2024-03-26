/*Készítsd el a FileSystemEntry absztrakt osztályt a ??. ábra alapján!
Az adattagok beállítása után amennyiben a kapott Folder objektum nem null, hívja meg az
addChild metódusát saját magával (lásd lentebb).
Az osztálynak legyen egy fullPath metódusa, mely az elem teljes elérési útjával tér vissza. A
visszaadott érték a tartalmazó mappa teljes elérési útja, egy / jel és az adott elem neve legyen
összefűzve, ha nincs tartalmazó mappa, akkor egyszerűen az elem neve. 

- parent : Folder
- name : String

+ FileSystemEntry(parent : Folder, name: String)
+ size() : long
+ fullPath() : String
+ setName(newName : String) : void
+ getName() : String
*/

public abstract class FileSystemEntry {
    private Folder parent;
    private String name;

    public FileSystemEntry(Folder parent, String name) {
        this.parent = parent;
        this.name = name;
        
        if (parent != null) {
            parent.addChild(this);
        }
    }
    
    public abstract long size();

    public String fullPath() {
        if (parent == null) {
            return name;
        }
        return parent.fullPath() + "/" + name;
    }

    public void setName(String newName) {
        this.name = newName;
    }

    public String getName() {
        return name;
    }
}