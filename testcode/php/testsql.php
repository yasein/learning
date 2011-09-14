<?php
        $conn = mysql_connect("216.156.209.102", "root", "qA123456");
        if(!$conn) {
                die('Could not connect: ' . mysql_error());
                return -1;
        }

        if(!mysql_select_db("fortitokens"))
                return -1;

        $sql = "select * from tokeninfo;";

        $result = mysql_query($sql);

        mysql_close($conn);

        print_r($result);
?>

