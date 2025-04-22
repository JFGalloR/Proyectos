package MyAmazon.MessageBox;

public class MessageBox {
    public static final String ICON_CHECKMARK = "/MyAmazon/MessageBox/Icons/CheckMark.png";
    public static final String ICON_CHECKED = "/MyAmazon/MessageBox/Icons/Checked.png";
    public static final String ICON_ERROR = "/MyAmazon/MessageBox/Icons/Error.png";
    public static final String ICON_INFO = "/MyAmazon/MessageBox/Icons/Info.png";
    public static final String ICON_STOP = "/MyAmazon/MessageBox/Icons/Stop.png";
    public static final String ICON_WARNIGN = "/MyAmazon/MessageBox/Icons/Warning.png";
    
    public static void showMB(String titulo, String texto, String icono)
    {
        java.awt.Color color = java.awt.Color.BLACK;
        switch(icono)
        {
            case ICON_CHECKMARK:
            case ICON_CHECKED:
                color = new java.awt.Color(108,186,108);
                break;
            case ICON_ERROR:
            case ICON_STOP:
                color = new java.awt.Color(238,89,89);
                break;
            case ICON_INFO:
                color = new java.awt.Color(56,121,165);
                break;
            case ICON_WARNIGN:
                color = new java.awt.Color(238,194,63);
                break;
        }
        MB mb = new MB(titulo, texto, icono, color);
        mb.show();
    }
}
