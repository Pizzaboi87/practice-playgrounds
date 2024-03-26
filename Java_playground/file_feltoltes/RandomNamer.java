/*
Hozd létre a RandomNamer osztályt a ??. ábra alapján!
Az ALPHABET konstans értéke:
ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_
A konstruktor várja a két adattagot paraméterként.
Az implementálandó metódust implementáld a véletlenszám-generátor és az ábécé konstans
segítségével. A java.util.Random objektumok nextInt(int bound) metódusa a [0-
bound) balról zárt, jobbról nyitott intervallumon ad vissza egy véletlen egész számot. Ennek
segítségével fűzz össze az ábécéből length darab véletlen betűt, és azt állítsd be a paraméterként kapott fájl új nevének.

- length : int
- rnd : java.util.Random
- ALPHABET : String

+ RandomNamer(rnd : java.util.Random, length : int)
*/

import java.util.Random;

public class RandomNamer implements Namer {
    private int length;
    private Random rnd;
    private static final String ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";

    public RandomNamer(Random rnd, int length) {
        this.rnd = rnd;
        this.length = length;
    }

    @Override
    public void rename(FileSystemEntry entry) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < length; i++) {
            sb.append(ALPHABET.charAt(rnd.nextInt(ALPHABET.length())));
        }
        entry.setName(sb.toString());
    }
}