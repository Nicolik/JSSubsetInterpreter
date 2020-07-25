print("Inserisci n: ");
n = readline();
aa = [readline()];
for (i = 0; i < n-1; i++) { 
    print("Inserisci elemento " + (i+1) + ": "); 
    aa.push(readline()); 
}

function reverse(aa) { 
    bb = [aa[aa.length-1]]; 
    for (i = 1; i < aa.length; i++) { 
        bb.push(aa[aa.length - i - 1]); 
    } 
    return bb; 
}

print("Array originale vale: " + aa);
cc = reverse(aa);
print("Array invertito vale: " + cc);