package MyAmazon.Fonts;

import java.io.InputStream;

public class Fonts {
    public static String EMBER_HE = "Ember_He";
    public static String EMBER_LT = "Ember_Lt";
    public static String EMBER_RG = "Ember_Rg";
    public java.awt.Font setFonts(String type, int style, float size) {
        try {
            InputStream is = getClass().getResourceAsStream("/MyAmazon/Fonts/" + type + ".ttf");
            java.awt.Font font = java.awt.Font.createFont(java.awt.Font.TRUETYPE_FONT, is);
            font = font.deriveFont(style, size);
            return font;
        } catch (Exception ex) {
            ex.printStackTrace();
            return null;
        }
    }
}
