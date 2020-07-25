bb = [];
function loadArray(aa, arraySize) {
    for (i = 0; i < arraySize; i++) {
        aa.push(readline());
    }
    return aa;
}
print("Inserisci numero elementi: ");
len = readline();

bb = loadArray(bb, len);

function modifyElementArray(aa, pos, newValue) {
    --pos;
    if (pos >= 0 && pos < aa.length) {
        aa[pos] = newValue;
    } else {
        print("Posizione non valida!");
    }
    return aa;
}

print("Inserisci nuovo elemento: ");
newEl = readline();
print("Inserisci posizione: ");
pos = readline();

cc = modifyElementArray(bb, pos, newEl);
print("Il vettore originale vale " + bb);
print("Il vettore modificato vale: " + cc);