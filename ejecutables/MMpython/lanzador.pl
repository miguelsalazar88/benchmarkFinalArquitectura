#!/usr/bin/perl

#Fichero para la ejecución

$path = "/Users/miguelsalazar/Documents/Arquitectura/examenFinal/Python";

@ejecutables = ("pythonMM.py");

@vectorSize = ("200", "400", "600", "800", "1000");

$repeticiones = 30;

foreach $exe (@ejecutables){
    foreach $vez (@vectorSize){
        $file = "$path/"."$exe"."-size-"."$vez".".txt";

        #print "$file \n"; #este es el nombre del archivo

        for ($i=0; $i< $repeticiones; $i++){
            system("python3 $exe $vez >> $file");
            #print "python3 $exe $vez \n";
        }
    }
}
