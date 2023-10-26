<?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $number = $_POST["number"];
        if ($number && is_numeric($number) && $number > 0) {
            echo "<h3>Multiplication Table for $number</h3>";
            echo "<style>
                    table {   
                        border: 1px solid black;
                    }
                    th, td {
                        border: 1px solid black;
                        text-align: center;
                    }
                  </style>";
            echo "<table>";
            echo "<tr><th>*</th>";
            for ($i = 1; $i <= $number; $i++) {
                echo "<th>$i</th>";
            }
            echo "</tr>";
            for ($i = 1; $i <= $number; $i++) {
                echo "<tr><th>$i</th>";
                for ($j = 1; $j <= $number; $j++) {
                    echo "<td>" . $i * $j . "</td>";
                }
                echo "</tr>";
            }
            echo "</table>";
        } else {
            echo "<p>Please enter a valid positive number.</p>";
        }
    }
?>
