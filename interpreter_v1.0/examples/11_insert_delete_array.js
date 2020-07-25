print("Inserisci n: ");
n = readline();
print("Inserisci elemento 0: ");
aa = [readline()];
for (i = 0; i < n-1; i++) { 
    print("Inserisci elemento " + (i+1) + ": "); 
    aa.push(readline()); 
}

print("Inserisci elemento da aggiungere: ");
srch = readline();
print("Inserisci la posizione (da 1 a length): ");
pos = readline();


function insertElementInArray(aa, srch, pos) {
    bb = [];
    if (pos <= 0 || pos > aa.length + 1) {
        print("Operazione non andata a buon fine");
        bb = aa;
    } else {
        for (i = 0; i < pos - 1; i++) {
            bb.push(aa[i]);
        }
        bb.push(srch);
        for(i = pos; i < aa.length + 1; i++){
            bb.push(aa[i-1]);
        }
    }
    return bb;
}

cc = insertElementInArray(aa, srch, pos);

print("Il vettore originale vale: " + aa);
print("Il vettore con l'inserimento vale: " + cc);

function deleteElementInArray(aa, pos) {
    --pos;
    // It looks strange but this is another way to define an empty array in our language
    bb = [0];
    bb.pop();
    j = 0;
    if ( pos < 0 || (pos > aa.length - 1) ) {
        print("Operazione non andata a buon fine");
        bb = aa;
    } else {     
        for (i = 0; i < aa.length; i++) {
            if (i != pos) {   
                bb.push(aa[i]);
            }   
        }
    }
    return bb;
}

print("Inserisci la posizione da rimuovere (da 1 a length): ");
pos = readline();

dd = deleteElementInArray(aa, pos);

print("Il vettore originale vale: " + aa);
print("Il vettore con l'eliminazione vale: " + dd);