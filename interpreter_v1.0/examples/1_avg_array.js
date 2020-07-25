print("Inserisci n: ");
n = readline();
// aa = [readline()];
aa = [];
for (i = 0; i < n; i++) { 
    print("Inserisci elemento " + (i+1) + ": ");
    aa.push(readline()); 
}
print("Il vettore inserito aa = " + aa);
tot = 0;
for (i = 0; i < n; i++) { 
    tot = tot + (+aa[i]); 
}
print("Il totale vale: " + tot);
avg = tot/n;
print("La media vale: " + avg );
