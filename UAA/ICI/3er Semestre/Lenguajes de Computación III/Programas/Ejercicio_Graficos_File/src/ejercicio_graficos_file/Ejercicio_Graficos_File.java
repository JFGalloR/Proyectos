/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package ejercicio_graficos_file;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.StringTokenizer;
import static javax.swing.WindowConstants.EXIT_ON_CLOSE;

/**
 *
 * @author xxjfg
 */
public class Ejercicio_Graficos_File {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            String line;
            FileReader file = new FileReader("src/Recursos/data.txt");
            BufferedReader br = new BufferedReader(file);

            line = br.readLine();
            StringTokenizer tokenizer = new StringTokenizer(line, ",");

            Pastel3D p = new Pastel3D(tokenizer.nextToken(), tokenizer.nextToken());
            p.pack();
            p.setLocationRelativeTo(null);
            p.setVisible(true);
            p.setDefaultCloseOperation(EXIT_ON_CLOSE);  
            file.close();
        } catch (IOException e) {
            System.out.println("Exception");
        }
    }

}
