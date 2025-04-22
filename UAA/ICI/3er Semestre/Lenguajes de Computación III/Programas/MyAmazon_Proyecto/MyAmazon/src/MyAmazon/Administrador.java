package MyAmazon;

import MyAmazon.Fonts.Fonts;
import MyAmazon.MessageBox.MessageBox;
import java.awt.Color;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.StringTokenizer;

public class Administrador extends javax.swing.JPanel {

    TablasAdmin tA1 = null;
    TablasAdmin tA2 = null;
    TablasAdmin tA3 = null;
    TablaInv tI;

    public Administrador() {
        initComponents();
        Opciones.setSelectedIndex(0);
    }


    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        BannerTop = new javax.swing.JPanel();
        Logo = new javax.swing.JLabel();
        Banner = new javax.swing.JLabel();
        Btn = new javax.swing.JLabel();
        Panel = new javax.swing.JPanel();
        Opciones = new javax.swing.JList<>();
        PanelLat = new javax.swing.JLabel();
        PanelAdmin = new javax.swing.JLabel();
        Titulo2 = new javax.swing.JLabel();
        Titulo1 = new javax.swing.JLabel();

        setBackground(new java.awt.Color(250, 250, 250));
        setLayout(null);

        BannerTop.setBackground(new java.awt.Color(255, 255, 255));
        BannerTop.setOpaque(false);
        BannerTop.setPreferredSize(new java.awt.Dimension(1138, 120));
        BannerTop.setLayout(null);

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
        Logo.setBounds(530, 10, 110, 60);

        Banner.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/BannerCompras.png"))); // NOI18N
        Banner.setVerticalAlignment(javax.swing.SwingConstants.TOP);
        BannerTop.add(Banner);
        Banner.setBounds(0, 0, 1150, 100);

        add(BannerTop);
        BannerTop.setBounds(0, 0, 1150, 100);

        Btn.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        Btn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsAdmin/BtnReg.png"))); // NOI18N
        Btn.setVerticalAlignment(javax.swing.SwingConstants.BOTTOM);
        Btn.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                BtnMouseMoved(evt);
            }
        });
        Btn.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                BtnMouseClicked(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                BtnMouseExited(evt);
            }
        });
        add(Btn);
        Btn.setBounds(70, 590, 140, 40);

        Panel.setBackground(new java.awt.Color(255, 255, 255));
        Panel.setLayout(null);
        add(Panel);
        Panel.setBounds(290, 180, 820, 430);

        Opciones.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 22));
        Opciones.setForeground(new java.awt.Color(51, 51, 51));
        Opciones.setModel(new javax.swing.AbstractListModel<String>() {
            String[] strings = { "   Clientes", "   Carrito", "   Inventario", "   Movimientos" };
            public int getSize() { return strings.length; }
            public String getElementAt(int i) { return strings[i]; }
        });
        Opciones.setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
        Opciones.setFocusable(false);
        Opciones.setRequestFocusEnabled(false);
        Opciones.setSelectionBackground(new java.awt.Color(26, 152, 255));
        Opciones.addListSelectionListener(new javax.swing.event.ListSelectionListener() {
            public void valueChanged(javax.swing.event.ListSelectionEvent evt) {
                OpcionesValueChanged(evt);
            }
        });
        add(Opciones);
        Opciones.setBounds(30, 200, 220, 130);

        PanelLat.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        PanelLat.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/MenuAdmin.png"))); // NOI18N
        add(PanelLat);
        PanelLat.setBounds(10, 0, 260, 650);

        PanelAdmin.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        PanelAdmin.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/PanelAdmin.png"))); // NOI18N
        add(PanelAdmin);
        PanelAdmin.setBounds(270, 160, 860, 470);

        Titulo2.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 40));
        Titulo2.setForeground(new java.awt.Color(51, 51, 51));
        Titulo2.setText("Administrador de ");
        add(Titulo2);
        Titulo2.setBounds(550, 90, 570, 70);

        Titulo1.setFont(new Fonts().setFonts(Fonts.EMBER_HE, 0, 42));
        Titulo1.setForeground(new java.awt.Color(26, 152, 255));
        Titulo1.setText("My Amazon.");
        add(Titulo1);
        Titulo1.setBounds(290, 90, 260, 70);
    }// </editor-fold>//GEN-END:initComponents

    private void LogoMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_LogoMouseClicked
        Inicio pI = new Inicio();
        pI.setSize(1150, 648);
        pI.setLocation(0, 0);
        MyAmazon.Panel.removeAll();
        MyAmazon.Panel.add(pI);
        MyAmazon.Panel.revalidate();
        MyAmazon.Panel.repaint();
    }//GEN-LAST:event_LogoMouseClicked

    private void LogoMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_LogoMouseExited
        Logo.setBorder(null);
    }//GEN-LAST:event_LogoMouseExited

    private void LogoMouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_LogoMouseMoved
        Logo.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(252, 175, 23)));
    }//GEN-LAST:event_LogoMouseMoved

    private void OpcionesValueChanged(javax.swing.event.ListSelectionEvent evt) {//GEN-FIRST:event_OpcionesValueChanged
        if (!evt.getValueIsAdjusting()) {
            switch (Opciones.getSelectedIndex()) {
                case 0:
                    Titulo2.setText("Administrador de clientes.");
                    tA1 = tA1 == null ? new TablasAdmin(0) : tA1;
                    tA1.setSize(820, 430);
                    tA1.setLocation(0, 0);
                    Panel.removeAll();
                    Panel.add(tA1);
                    Panel.revalidate();
                    Panel.repaint();
                    break;
                case 1:
                    Titulo2.setText("Administrador de carrito.");
                    tA2 = tA2 == null ? new TablasAdmin(1) : tA2;
                    tA2.setSize(820, 430);
                    tA2.setLocation(0, 0);
                    Panel.removeAll();
                    Panel.add(tA2);
                    Panel.revalidate();
                    Panel.repaint();
                    break;
                case 2:
                    Titulo2.setText("Administrador de inventario.");
                    tI = tI == null ? new TablaInv() : tI;
                    tI.setSize(820, 430);
                    tI.setLocation(0, 0);
                    Panel.removeAll();
                    Panel.add(tI);
                    Panel.revalidate();
                    Panel.repaint();
                    break;
                case 3:
                    Titulo2.setText("Administrador de movimientos.");
                    tA3 = tA3 == null ? new TablasAdmin(3) : tA3;
                    tA3.setSize(820, 430);
                    tA3.setLocation(0, 0);
                    Panel.removeAll();
                    Panel.add(tA3);
                    Panel.revalidate();
                    Panel.repaint();
                    break;
            }
        }
    }//GEN-LAST:event_OpcionesValueChanged

    private void BtnMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseExited
        Btn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsAdmin/BtnReg.png")));

    }//GEN-LAST:event_BtnMouseExited

    private void BtnMouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseMoved
        Btn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsAdmin/BtnReg_H.png")));
    }//GEN-LAST:event_BtnMouseMoved

    private void BtnMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseClicked
        Inicio pI = new Inicio();
        pI.setSize(1150, 648);
        pI.setLocation(0, 0);
        MyAmazon.Panel.removeAll();
        MyAmazon.Panel.add(pI);
        MyAmazon.Panel.revalidate();
        MyAmazon.Panel.repaint();
    }//GEN-LAST:event_BtnMouseClicked


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel Banner;
    private javax.swing.JPanel BannerTop;
    private javax.swing.JLabel Btn;
    private javax.swing.JLabel Logo;
    private javax.swing.JList<String> Opciones;
    private javax.swing.JPanel Panel;
    private javax.swing.JLabel PanelAdmin;
    private javax.swing.JLabel PanelLat;
    private javax.swing.JLabel Titulo1;
    private javax.swing.JLabel Titulo2;
    // End of variables declaration//GEN-END:variables
}
