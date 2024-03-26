/*
Készítsd el a Folder osztályt a ??. ábra alapján!
A saját adattagja legyen alapból null.
Írd meg a saját metódusát a ??. ábra alapján! A metódus ellenőrizze, hogy a saját tömbje
null-e:
• ha igen, hozzon létre egy új tömböt egyetlen elemmel, ami a paraméterként kapott referencia legyen, ezt állítsa be az adattagnak.
• ha nem, hozzon létre egy új eggyel nagyobb méretű tömböt, másolja át bele a jelenlegi
elemeket, majd utolsóként szúrja be a paraméterként kapottat. Ez után állítsa be az új
tömböt adattagnak.
Valósítsd meg az absztrakt metódust. Ha a mappa üres, térjen vissza nullával, egyébként a
tartalmazott elemek méretének összegével 

- children : FileSystemEntry[ ]

- children : FileSystemEntry[ ]
+ Folder(parent : Folder, name: String)
+ addChild(child : FileSystemEntry) : void
*/

public class Folder extends FileSystemEntry {
    private FileSystemEntry[] children = null;

    public Folder(Folder parent, String name) {
        super(parent, name);
    }

    @Override
    public long size() {
        if (children == null) {
            return 0;
        }
        long sum = 0;
        for (FileSystemEntry child : children) {
            sum += child.size();
        }
        return sum;
    }

    public void addChild(FileSystemEntry child) {
        if (children == null) {
            children = new FileSystemEntry[] { child };
        } else {
            FileSystemEntry[] newChildren = new FileSystemEntry[children.length + 1];
            System.arraycopy(children, 0, newChildren, 0, children.length);
            newChildren[children.length] = child;
            children = newChildren;
        }
    }
}