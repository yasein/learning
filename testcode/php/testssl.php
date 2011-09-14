<?php

    function strtohex($x) 
    {
        $s='';
        foreach (str_split($x) as $c) $s.=sprintf("%02X",ord($c));
        return($s);
    } 
    
    $source = 'It works !';

    $iv = "1234567812345678";
    $pass = '1234567812345678';
    $method = 'aes-128-cbc';

    echo "\niv in hex to use: ".strtohex ($iv);
    echo "\nkey in hex to use: ".strtohex ($pass);
    echo "\n";

    file_put_contents ('./file.encrypted',openssl_encrypt ($source, $method, $pass, true, $iv));

    $exec = "openssl enc -".$method." -d -in file.encrypted -nosalt -nopad -K ".strtohex($pass)." -iv ".strtohex($iv);

    echo 'executing: '.$exec."\n\n";
    echo exec ($exec);
    echo "\n";

    print_r(openssl_get_cipher_methods());
?>
