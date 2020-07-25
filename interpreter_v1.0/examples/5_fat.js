function fat(i) { 
    print("Entering in fat() with: " + i); 
    if (i < 0) { c = -1; } 
    else { 
        if (i == 0) { c = 1; } 
        else { 
            c = i * fat(i-1);   
        }  
    } 
    return c; 
}

input = 0;
print("Inserisci 0 per uscire dal loop");
do { 
input = readline(); 
out = fat(input); 
print("Il fattoriale di " + input + " vale: " + out); 
} while(input > 0)
