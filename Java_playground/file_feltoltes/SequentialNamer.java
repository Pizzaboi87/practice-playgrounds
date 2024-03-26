/*
Hozd létre a SequentialNamer osztályt a ??. ábra alapján!
A saját adattagja az objektum létrejöttekor legyen 1.
Az implementálandó metódust implementáld úgy, hogy a bejegyzés eredeti nevéhez hozzáfűzöl
egy alulvonás karaktert és a saját adattag aktuális értékét, majd ezt állítod be új névnek.
Növeld eggyel a saját adattag értékét.

- index : int
*/

public class SequentialNamer implements Namer {
    private int index = 1;

    @Override
    public void rename(FileSystemEntry entry) {
        entry.setName(entry.getName() + "_" + index);
        index++;
    }
}