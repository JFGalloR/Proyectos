package MyAmazon;

import MyAmazon.Fonts.Fonts;
import MyAmazon.MessageBox.MessageBox;
import java.awt.Color;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.StringTokenizer;

public class Compras extends javax.swing.JPanel {

    Connection conn;
    public static int clave;
    public static String usuario;
    PanelFiltro pF;
    public String bus = "";
    String mensaje = "Buscar en My Amazon";

    public Compras(int clave) {
        this.conn = MyAmazon.conn;
        this.clave = clave;
        informacion();
        initComponents();
        pF = new PanelFiltro(this);
        actualizar();
        pantallaInicial();
    }

    public Compras() {
        this.conn = MyAmazon.conn;
        initComponents();
        pF = new PanelFiltro(this);
        actualizar();
        pantallaInicial();
    }

    public void informacion() {
        try {
            Statement stmt = conn.createStatement();
            ResultSet resultSet = stmt.executeQuery("SELECT * FROM " + MyAmazon.clientes + " WHERE clave = " + clave + ";");

            if (resultSet.next()) {
                usuario = resultSet.getString("usuario");
            }

        } catch (SQLException ex) {
            MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
        }
    }

    public void pantallaInicial(){
        try {
            Statement stmt = conn.createStatement();
            ResultSet resultSet = stmt.executeQuery(
                    "SELECT * FROM " + MyAmazon.inventario + ";");
            Productos.setPreferredSize(new java.awt.Dimension(1138, 1110));
            Productos.removeAll();

            if (resultSet.next()) {
                int aux = Productos.getPreferredSize().width;
                InicioCompras iC = new InicioCompras(this);
                Productos.add(iC);
                ScrollPane.getVerticalScrollBar().setUnitIncrement(25);
                
                do {
                    int clave_p = resultSet.getInt("clave");
                    String dir = resultSet.getString("imagen");
                    String prod = resultSet.getString("producto");
                    int cant = resultSet.getInt("cantidad");
                    float precio = resultSet.getFloat("precio");

                    Producto p = new Producto(this, clave_p, prod, dir, cant, precio);
                    aux -= p.getPreferredSize().width;

                    if (aux < 0) {
                        Productos.setPreferredSize(
                                new java.awt.Dimension(Productos.getPreferredSize().width,
                                        Productos.getPreferredSize().height + p.getPreferredSize().height + 10));
                        aux = Productos.getPreferredSize().width;
                        aux -= p.getPreferredSize().width;
                    }
                    Productos.add(p);
                } while (resultSet.next());
                Productos.revalidate();
                Productos.repaint();
            } else {
                javax.swing.JLabel l = new javax.swing.JLabel("- No hay inventario -");
                l.setHorizontalAlignment(javax.swing.JLabel.CENTER);
                l.setPreferredSize(new java.awt.Dimension(300, 100));
                l.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 24));
                pF.setPreferredSize(new java.awt.Dimension(1150, 82));
                Productos.add(pF);
                Productos.add(l);
                Productos.revalidate();
                Productos.repaint();
                javax.swing.SwingUtilities.invokeLater(() -> {
                    MessageBox.showMB("My Amazon", "No hay inventario.", MessageBox.ICON_INFO);
                });
            }
        } catch (SQLException ex) {
            MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
        }

        javax.swing.SwingUtilities.invokeLater(() -> {
            Productos.revalidate();
            Productos.repaint();
            ScrollPane.getVerticalScrollBar().setValue(0);
        });
    }
    
    public void agregarProductos(String busq) {
        try {
            Statement stmt = conn.createStatement();
            System.out.println("   -> SELECT * FROM " + MyAmazon.inventario + " " + bus + busq + ";");
            ResultSet resultSet = stmt.executeQuery(
                    "SELECT * FROM " + MyAmazon.inventario + " " + bus + busq + ";");
            Productos.setPreferredSize(new java.awt.Dimension(1138, 500));
            Productos.removeAll();

            if (resultSet.next()) {
                int aux = Productos.getPreferredSize().width;

                ScrollPane.getVerticalScrollBar().setUnitIncrement(25);
                Productos.add(pF);

                do {
                    int clave_p = resultSet.getInt("clave");
                    String dir = resultSet.getString("imagen");
                    String prod = resultSet.getString("producto");
                    int cant = resultSet.getInt("cantidad");
                    float precio = resultSet.getFloat("precio");

                    Producto p = new Producto(this, clave_p, prod, dir, cant, precio);
                    aux -= p.getPreferredSize().width;

                    if (aux < 0) {
                        Productos.setPreferredSize(
                                new java.awt.Dimension(Productos.getPreferredSize().width,
                                        Productos.getPreferredSize().height + p.getPreferredSize().height + 10));
                        aux = Productos.getPreferredSize().width;
                        aux -= p.getPreferredSize().width;
                    }
                    Productos.add(p);
                } while (resultSet.next());
                Productos.revalidate();
                Productos.repaint();
            } else {
                javax.swing.JLabel l = new javax.swing.JLabel("- No hay inventario -");
                l.setHorizontalAlignment(javax.swing.JLabel.CENTER);
                l.setPreferredSize(new java.awt.Dimension(300, 100));
                l.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 24));
                pF.setPreferredSize(new java.awt.Dimension(1150, 82));
                Productos.add(pF);
                Productos.add(l);
                Productos.revalidate();
                Productos.repaint();
                javax.swing.SwingUtilities.invokeLater(() -> {
                    MessageBox.showMB("My Amazon", "No hay inventario.", MessageBox.ICON_INFO);
                });
            }
        } catch (SQLException ex) {
            MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
        }

        javax.swing.SwingUtilities.invokeLater(() -> {
            Productos.revalidate();
            Productos.repaint();
            ScrollPane.getVerticalScrollBar().setValue(0);
        });
    }

    public void actualizar() {
        try {
            Statement stmt = conn.createStatement();
            ResultSet resultSet = stmt.executeQuery("SELECT COUNT(*) FROM " + MyAmazon.carrito + " WHERE clave_usuario = '" + clave + "';");

            if (resultSet.next()) {
                if (resultSet.getInt(1) > 9) {
                    Num.setText("9+");
                } else {
                    Num.setText(Integer.toString(resultSet.getInt(1)));
                }
            } else {
                Num.setText("0");
            }
        } catch (SQLException ex) {
            MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
        }
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        BannerTop = new javax.swing.JPanel();
        Carrito = new javax.swing.JLabel();
        Num = new javax.swing.JLabel();
        Opcion = new javax.swing.JComboBox<>();
        Label = new javax.swing.JLabel();
        Usuario = new javax.swing.JLabel();
        Saludo = new javax.swing.JLabel();
        BtnBuscar = new javax.swing.JLabel();
        Buscador = new javax.swing.JTextField();
        Logo = new javax.swing.JLabel();
        Banner = new javax.swing.JLabel();
        ScrollPane = new javax.swing.JScrollPane();
        Productos = new javax.swing.JPanel();

        setLayout(null);

        BannerTop.setBackground(new java.awt.Color(255, 255, 255));
        BannerTop.setOpaque(false);
        BannerTop.setPreferredSize(new java.awt.Dimension(1138, 120));
        BannerTop.setLayout(null);

        Carrito.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsCompras/Carrito.png"))); // NOI18N
        Carrito.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                CarritoMouseMoved(evt);
            }
        });
        Carrito.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                CarritoMouseClicked(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                CarritoMouseExited(evt);
            }
        });
        BannerTop.add(Carrito);
        Carrito.setBounds(1070, 20, 50, 40);

        Num.setFont(new Fonts().setFonts(Fonts.EMBER_HE, 0, 18));
        Num.setForeground(new java.awt.Color(252, 135, 23));
        Num.setText("0");
        Num.setToolTipText("");
        BannerTop.add(Num);
        Num.setBounds(1090, 20, 30, 20);

        Opcion.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 12));
        Opcion.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { " - - -", "Cuenta", "Carrito", "Facturas" }));
        Opcion.setToolTipText("");
        Opcion.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                OpcionActionPerformed(evt);
            }
        });
        BannerTop.add(Opcion);
        Opcion.setBounds(930, 40, 110, 22);

        Label.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 10));
        Label.setForeground(new java.awt.Color(255, 255, 255));
        Label.setText(" Menu de cuenta:");
        Label.setToolTipText("");
        BannerTop.add(Label);
        Label.setBounds(930, 20, 120, 20);

        Usuario.setFont(new Fonts().setFonts(Fonts.EMBER_HE, 0, 24));
        Usuario.setForeground(new java.awt.Color(255, 255, 255));
        Usuario.setText(this.usuario);
        Usuario.setVerticalAlignment(javax.swing.SwingConstants.TOP);
        BannerTop.add(Usuario);
        Usuario.setBounds(800, 30, 130, 30);

        Saludo.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        Saludo.setForeground(new java.awt.Color(255, 255, 255));
        Saludo.setText("Hola,");
        Saludo.setVerticalAlignment(javax.swing.SwingConstants.TOP);
        BannerTop.add(Saludo);
        Saludo.setBounds(800, 20, 37, 20);

        BtnBuscar.setBackground(new java.awt.Color(252, 175, 23));
        BtnBuscar.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        BtnBuscar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsCompras/Lupa.png"))); // NOI18N
        BtnBuscar.setOpaque(true);
        BtnBuscar.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                BtnBuscarMouseMoved(evt);
            }
        });
        BtnBuscar.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                BtnBuscarMouseClicked(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                BtnBuscarMouseExited(evt);
            }
        });
        BannerTop.add(BtnBuscar);
        BtnBuscar.setBounds(740, 20, 40, 40);

        Buscador.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        Buscador.setForeground(new java.awt.Color(153, 153, 153));
        Buscador.setText(mensaje);
        Buscador.setBorder(javax.swing.BorderFactory.createEmptyBorder(1, 15, 1, 15));
        Buscador.setNextFocusableComponent(ScrollPane);
        Buscador.setOpaque(true);
        Buscador.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                BuscadorFocusGained(evt);
            }
            public void focusLost(java.awt.event.FocusEvent evt) {
                BuscadorFocusLost(evt);
            }
        });
        BannerTop.add(Buscador);
        Buscador.setBounds(240, 20, 500, 40);

        Logo.setBackground(new java.awt.Color(45, 60, 90));
        Logo.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        Logo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/LogoB.png"))); // NOI18N
        Logo.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                LogoMouseMoved(evt);
            }
        });
        Logo.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                LogoMouseClicked(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                LogoMouseExited(evt);
            }
        });
        BannerTop.add(Logo);
        Logo.setBounds(30, 10, 110, 60);

        Banner.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/BannerCompras.png"))); // NOI18N
        Banner.setVerticalAlignment(javax.swing.SwingConstants.TOP);
        BannerTop.add(Banner);
        Banner.setBounds(0, 0, 1150, 100);

        add(BannerTop);
        BannerTop.setBounds(0, 0, 1150, 100);

        ScrollPane.setBorder(null);
        ScrollPane.setHorizontalScrollBarPolicy(javax.swing.ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
        ScrollPane.setPreferredSize(new java.awt.Dimension(1138, 500));

        Productos.setBackground(new java.awt.Color(255, 255, 255));
        Productos.setPreferredSize(new java.awt.Dimension(1138, 500));
        ScrollPane.setViewportView(Productos);

        add(ScrollPane);
        ScrollPane.setBounds(0, 80, 1150, 570);
    }// </editor-fold>//GEN-END:initComponents

    private void LogoMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_LogoMouseClicked
        Compras cmp = new Compras();
        cmp.setSize(1150, 648);
        cmp.setLocation(0, 0);
        MyAmazon.Panel.removeAll();
        MyAmazon.Panel.add(cmp);
        MyAmazon.Panel.revalidate();
        MyAmazon.Panel.repaint();
    }//GEN-LAST:event_LogoMouseClicked

    private void LogoMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_LogoMouseExited
        Logo.setBorder(null);
    }//GEN-LAST:event_LogoMouseExited

    private void LogoMouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_LogoMouseMoved
        Logo.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(252, 175, 23)));
    }//GEN-LAST:event_LogoMouseMoved

    private void BuscadorFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_BuscadorFocusGained
        if (Buscador.getText().equalsIgnoreCase(mensaje)) {
            Buscador.setForeground(Color.BLACK);
            Buscador.setText("");
        }
    }//GEN-LAST:event_BuscadorFocusGained

    private void BuscadorFocusLost(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_BuscadorFocusLost
        if (Buscador.getText().isBlank()) {
            Buscador.setForeground(new Color(153, 153, 153));
            Buscador.setText(mensaje);
        }
    }//GEN-LAST:event_BuscadorFocusLost

    private void BtnBuscarMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnBuscarMouseExited
        BtnBuscar.setBackground(new Color(252, 175, 23));
    }//GEN-LAST:event_BtnBuscarMouseExited

    private void BtnBuscarMouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnBuscarMouseMoved
        BtnBuscar.setBackground(new Color(214, 147, 16));
    }//GEN-LAST:event_BtnBuscarMouseMoved

    private void BtnBuscarMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnBuscarMouseClicked

        if (!Buscador.getText().isBlank() && !Buscador.getText().equalsIgnoreCase(mensaje)) {
            StringTokenizer st = new StringTokenizer(Buscador.getText());

            if (st.hasMoreTokens()) {
                String token = st.nextToken();
                bus = "WHERE (producto LIKE '%" + token + "%'";
                while (st.hasMoreTokens()) {
                    token = st.nextToken();
                    bus += " OR producto LIKE '%" + token + "%'";
                }
                bus += ")";
            }
            agregarProductos("");
        }
    }//GEN-LAST:event_BtnBuscarMouseClicked

    private void OpcionActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_OpcionActionPerformed
        if (Opcion.getSelectedIndex() != 0) {
            MenuCuenta oc = null;
            switch (Opcion.getSelectedIndex()) {
                case 1 ->
                    oc = new MenuCuenta(0);
                case 2 ->
                    oc = new MenuCuenta(1);
                case 3 ->
                    oc = new MenuCuenta(2);
            }
            oc.setSize(1150, 648);
            oc.setLocation(0, 0);
            MyAmazon.Panel.removeAll();
            MyAmazon.Panel.add(oc);
            MyAmazon.Panel.revalidate();
            MyAmazon.Panel.repaint();
        }
    }//GEN-LAST:event_OpcionActionPerformed

    private void CarritoMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_CarritoMouseExited
        Carrito.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsCompras/Carrito.png")));
    }//GEN-LAST:event_CarritoMouseExited

    private void CarritoMouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_CarritoMouseMoved
        Carrito.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsCompras/Carrito_H.png")));
    }//GEN-LAST:event_CarritoMouseMoved

    private void CarritoMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_CarritoMouseClicked
        MenuCuenta oc = new MenuCuenta(1);
        oc.setSize(1150, 648);
        oc.setLocation(0, 0);
        MyAmazon.Panel.removeAll();
        MyAmazon.Panel.add(oc);
        MyAmazon.Panel.revalidate();
        MyAmazon.Panel.repaint();
    }//GEN-LAST:event_CarritoMouseClicked


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel Banner;
    private javax.swing.JPanel BannerTop;
    private javax.swing.JLabel BtnBuscar;
    private javax.swing.JTextField Buscador;
    private javax.swing.JLabel Carrito;
    private javax.swing.JLabel Label;
    private javax.swing.JLabel Logo;
    private javax.swing.JLabel Num;
    private javax.swing.JComboBox<String> Opcion;
    private javax.swing.JPanel Productos;
    private javax.swing.JLabel Saludo;
    private javax.swing.JScrollPane ScrollPane;
    private javax.swing.JLabel Usuario;
    // End of variables declaration//GEN-END:variables
}
