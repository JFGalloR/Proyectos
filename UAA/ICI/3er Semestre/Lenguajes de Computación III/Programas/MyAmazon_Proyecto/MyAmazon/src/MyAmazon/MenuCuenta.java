package MyAmazon;

import MyAmazon.Fonts.Fonts;
import javax.swing.JLabel;

public class MenuCuenta extends javax.swing.JPanel {

    CuentaOpc oc = null;
    Carrito c = null;
    public static Facturas f = null;

    public MenuCuenta(int opc) {
        initComponents();
        Opciones.setSelectedIndex(opc);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        TopBanner = new javax.swing.JLabel();
        BtnRegresar = new javax.swing.JLabel();
        BtnSalir = new javax.swing.JLabel();
        Opciones = new javax.swing.JList<>();
        Logo = new javax.swing.JLabel();
        Banner = new javax.swing.JLabel();
        Titulo2 = new javax.swing.JLabel();
        Titulo1 = new javax.swing.JLabel();
        Panel = new javax.swing.JPanel();
        BackgroundPanel = new javax.swing.JLabel();

        setBackground(new java.awt.Color(250, 250, 250));
        setLayout(null);

        TopBanner.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        TopBanner.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/BannerMenuCuenta.png"))); // NOI18N
        TopBanner.setVerticalAlignment(javax.swing.SwingConstants.TOP);
        add(TopBanner);
        TopBanner.setBounds(0, 0, 1150, 40);

        BtnRegresar.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        BtnRegresar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsMenuCuenta/BtnRegresar.png"))); // NOI18N
        BtnRegresar.setVerticalAlignment(javax.swing.SwingConstants.TOP);
        BtnRegresar.setName("BtnRegresar"); // NOI18N
        BtnRegresar.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                BtnMouseMoved(evt);
            }
        });
        BtnRegresar.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                BtnRegresarMouseClicked(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                BtnMouseExited(evt);
            }
        });
        add(BtnRegresar);
        BtnRegresar.setBounds(100, 560, 140, 40);

        BtnSalir.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        BtnSalir.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsMenuCuenta/BtnSalir.png"))); // NOI18N
        BtnSalir.setName("BtnSalir"); // NOI18N
        BtnSalir.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                BtnMouseMoved(evt);
            }
        });
        BtnSalir.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                BtnSalirMouseClicked(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                BtnMouseExited(evt);
            }
        });
        add(BtnSalir);
        BtnSalir.setBounds(100, 590, 140, 40);

        Opciones.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 22));
        Opciones.setForeground(new java.awt.Color(51, 51, 51));
        Opciones.setModel(new javax.swing.AbstractListModel<String>() {
            String[] strings = { "   Cuenta", "   Carrito", "   Facturas" };
            public int getSize() { return strings.length; }
            public String getElementAt(int i) { return strings[i]; }
        });
        Opciones.setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
        Opciones.setFocusable(false);
        Opciones.setRequestFocusEnabled(false);
        Opciones.setSelectionBackground(new java.awt.Color(247, 153, 61));
        Opciones.addListSelectionListener(new javax.swing.event.ListSelectionListener() {
            public void valueChanged(javax.swing.event.ListSelectionEvent evt) {
                OpcionesValueChanged(evt);
            }
        });
        add(Opciones);
        Opciones.setBounds(60, 210, 220, 110);

        Logo.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        Logo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/LogoN.png"))); // NOI18N
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
        add(Logo);
        Logo.setBounds(80, 50, 180, 93);

        Banner.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        Banner.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/MenuCuenta.png"))); // NOI18N
        add(Banner);
        Banner.setBounds(20, 0, 300, 648);

        Titulo2.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 42));
        Titulo2.setForeground(new java.awt.Color(51, 51, 51));
        add(Titulo2);
        Titulo2.setBounds(500, 50, 620, 70);

        Titulo1.setFont(new Fonts().setFonts(Fonts.EMBER_HE, 0, 42));
        Titulo1.setForeground(new java.awt.Color(247, 153, 61));
        Titulo1.setText("Cuenta.");
        add(Titulo1);
        Titulo1.setBounds(330, 50, 160, 70);

        Panel.setBackground(new java.awt.Color(255, 255, 255));

        javax.swing.GroupLayout PanelLayout = new javax.swing.GroupLayout(Panel);
        Panel.setLayout(PanelLayout);
        PanelLayout.setHorizontalGroup(
            PanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 770, Short.MAX_VALUE)
        );
        PanelLayout.setVerticalGroup(
            PanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 460, Short.MAX_VALUE)
        );

        add(Panel);
        Panel.setBounds(340, 150, 770, 460);

        BackgroundPanel.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/PanelCuenta.png"))); // NOI18N
        add(BackgroundPanel);
        BackgroundPanel.setBounds(330, 140, 790, 480);
    }// </editor-fold>//GEN-END:initComponents

    private void LogoMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_LogoMouseClicked
        Compras cmp = new Compras(Compras.clave);
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

    private void BtnMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseExited
        JLabel btn = (JLabel) evt.getSource();
        btn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsMenuCuenta/" + btn.getName() + ".png")));
    }//GEN-LAST:event_BtnMouseExited

    private void BtnMouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseMoved
        JLabel btn = (JLabel) evt.getSource();
        btn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsMenuCuenta/" + btn.getName() + "_H.png")));
    }//GEN-LAST:event_BtnMouseMoved

    private void BtnRegresarMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnRegresarMouseClicked
        Compras cmp = new Compras(Compras.clave);
        cmp.setSize(1150, 648);
        cmp.setLocation(0, 0);
        MyAmazon.Panel.removeAll();
        MyAmazon.Panel.add(cmp);
        MyAmazon.Panel.revalidate();
        MyAmazon.Panel.repaint();
    }//GEN-LAST:event_BtnRegresarMouseClicked

    private void BtnSalirMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnSalirMouseClicked
        Inicio pI = new Inicio();
        pI.setSize(1150, 648);
        pI.setLocation(0, 0);
        MyAmazon.Panel.removeAll();
        MyAmazon.Panel.add(pI);
        MyAmazon.Panel.revalidate();
        MyAmazon.Panel.repaint();
    }//GEN-LAST:event_BtnSalirMouseClicked

    private void OpcionesValueChanged(javax.swing.event.ListSelectionEvent evt) {//GEN-FIRST:event_OpcionesValueChanged
        if (!evt.getValueIsAdjusting()) {
            switch (Opciones.getSelectedIndex()) {
                case 0:
                    Titulo2.setText("Opciones de cuenta.");
                    oc = oc == null ? new CuentaOpc() : oc;
                    oc.setSize(770, 460);
                    oc.setLocation(0, 0);
                    Panel.removeAll();
                    Panel.add(oc);
                    Panel.revalidate();
                    Panel.repaint();
                    break;
                case 1:
                    Titulo2.setText("Carrito de compras.");
                    c = c == null ? new Carrito() : c;
                    c.setSize(770, 460);
                    c.setLocation(0, 0);
                    Panel.removeAll();
                    Panel.add(c);
                    Panel.revalidate();
                    Panel.repaint();
                    break;
                case 2:
                    Titulo2.setText("Facturas.");
                    f = f == null ? new Facturas() : f;
                    f.setSize(770, 460);
                    f.setLocation(0, 0);
                    Panel.removeAll();
                    Panel.add(f);
                    Panel.revalidate();
                    Panel.repaint();
                    break;
            }
        }
    }//GEN-LAST:event_OpcionesValueChanged


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel BackgroundPanel;
    private javax.swing.JLabel Banner;
    private javax.swing.JLabel BtnRegresar;
    private javax.swing.JLabel BtnSalir;
    private javax.swing.JLabel Logo;
    private javax.swing.JList<String> Opciones;
    private javax.swing.JPanel Panel;
    private javax.swing.JLabel Titulo1;
    private javax.swing.JLabel Titulo2;
    private javax.swing.JLabel TopBanner;
    // End of variables declaration//GEN-END:variables
}
