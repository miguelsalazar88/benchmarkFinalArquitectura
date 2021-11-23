#!/usr/bin/perl

#Fichero para la ejecución

$path = "/Users/miguelsalazar/Documents/Arquitectura/examenFinal/Ejecuciones";

@ejecutables = (MMcpp, mm1c);

@vectorSize = ("200", "400", "600", "800", "1000");

$repeticiones = 30;

foreach $exe (@ejecutables){
    foreach $vez (@vectorSize){
        $file = "$path/"."$exe"."-size"."$vez".".txt";

        #print "$file \n"; #este es el nombre del archivo

        for ($i=0; $i< $repeticiones; $i++){
            system("$path/$exe $vez >> $file");
            #print "$path/$exe $vez \n";
        }
    }
}
