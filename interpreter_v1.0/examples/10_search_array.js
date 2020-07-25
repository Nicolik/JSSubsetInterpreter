print("Inserisci n: ");
n = readline();
print("Inserisci elemento 0: ");
aa = [readline()];
for (i = 0; i < n-1; i++) { 
    print("Inserisci elemento " + (i+1) + ": "); 
    aa.push(readline()); 
}

print("Inserisci elemento da cercare: ");
srch = readline();

function searchElementInArray(aa, srch) {
    cont = 0;
    for (i = 0; i < aa.length; i++) {
        if(aa[i] == srch) cont++;
    }
    return cont;
}

res = searchElementInArray(aa, srch);

if (res == 0) print("Non sono stati trovati elementi");
else print("Nel vettore " + aa + " sono presenti " + res + " occorrenze di " + srch);