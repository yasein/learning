<?php

$iv = "fortitokenmobile";
$method = "aes-128-cbc";

function encrypt_seed($seed, $udid, $raw)
{
    global $iv, $method;
    
    $pass = $udid;
    $source = $seed;

    $encrypt = openssl_encrypt($source, $method, $pass, $raw, $iv);

    return $encrypt;
}

function decrypt_seed($encrypt, $udid, $raw)
{
    global $iv, $method;

    $pass = $udid;
    
    $seed = openssl_decrypt($encrypt, $method, $pass, $raw, $iv);
    
    return $seed;
}


?>

<?php

$seed = "FAEABABABABABBABABABABABAB";

$udid = "forti_mobile";

$encrypt_en = encrypt_seed($seed, $udid, false);
echo "encrypt and encoded seed: ".$encrypt_en;
file_put_contents('./seed.enc.encoded', $encrypt_en);
echo "\n";
$decrypt = decrypt_seed($encrypt_en, $udid, false);
echo "decrypted seed: ".$decrypt;

?>


