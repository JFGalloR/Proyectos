package MyAmazon;

import javax.swing.ImageIcon;
import javax.swing.JLabel;

public class Inicio extends javax.swing.JPanel {
    
    public Inicio() {
        initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        BtnAdmin = new javax.swing.JLabel();
        BtnIden = new javax.swing.JLabel();
        BtnReg = new javax.swing.JLabel();
        Inicio = new javax.swing.JLabel();
        Background = new javax.swing.JLabel();

        setLayout(null);

        BtnAdmin.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        BtnAdmin.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsInicio/BtnAdmin.png"))); // NOI18N
        BtnAdmin.setName("BtnAdmin"); // NOI18N
        BtnAdmin.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                BtnMouseMoved(evt);
            }
        });
        BtnAdmin.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                BtnAdminMouseClicked(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                BtnMouseExited(evt);
            }
        });
        add(BtnAdmin);
        BtnAdmin.setBounds(840, 590, 240, 40);

        BtnIden.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        BtnIden.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsInicio/BtnIden.png"))); // NOI18N
        BtnIden.setName("BtnIden"); // NOI18N
        BtnIden.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                BtnMouseMoved(evt);
            }
        });
        BtnIden.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                BtnIdenMouseClicked(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                BtnMouseExited(evt);
            }
        });
        add(BtnIden);
        BtnIden.setBounds(840, 300, 240, 50);

        BtnReg.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        BtnReg.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsInicio/BtnReg.png"))); // NOI18N
        BtnReg.setName("BtnReg"); // NOI18N
        BtnReg.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                BtnMouseMoved(evt);
            }
        });
        BtnReg.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                BtnRegMouseClicked(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                BtnMouseExited(evt);
            }
        });
        add(BtnReg);
        BtnReg.setBounds(840, 350, 240, 50);

        Inicio.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
        Inicio.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/Inicio.png"))); // NOI18N
        add(Inicio);
        Inicio.setBounds(720, 0, 430, 650);

        Background.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Backgrounds/Inicio.gif"))); // NOI18N
        add(Background);
        Background.setBounds(0, 0, 1150, 650);
    }// </editor-fold>//GEN-END:initComponents

    private void BtnMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseExited
        JLabel btn = (JLabel) evt.getSource();
        btn.setIcon(new ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsInicio/" + btn.getName() + ".png")));
    }//GEN-LAST:event_BtnMouseExited

    private void BtnMouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseMoved
        JLabel btn = (JLabel) evt.getSource();
        btn.setIcon(new ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsInicio/" + btn.getName() + "_H.png")));
    }//GEN-LAST:event_BtnMouseMoved

    private void BtnIdenMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnIdenMouseClicked
        IdenReg ir = new IdenReg(true);
        ir.setSize(1150, 648);
        ir.setLocation(0, 0);
        MyAmazon.Panel.removeAll();
        MyAmazon.Panel.add(ir);
        MyAmazon.Panel.revalidate();
        MyAmazon.Panel.repaint();
    }//GEN-LAST:event_BtnIdenMouseClicked

    private void BtnRegMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnRegMouseClicked
        IdenReg ir = new IdenReg(false);
        ir.setSize(1150, 648);
        ir.setLocation(0, 0);
        MyAmazon.Panel.removeAll();
        MyAmazon.Panel.add(ir);
        MyAmazon.Panel.revalidate();
        MyAmazon.Panel.repaint();
    }//GEN-LAST:event_BtnRegMouseClicked

    private void BtnAdminMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnAdminMouseClicked
        Administrador a = new Administrador();
        a.setSize(1150, 648);
        a.setLocation(0, 0);
        MyAmazon.Panel.removeAll();
        MyAmazon.Panel.add(a);
        MyAmazon.Panel.revalidate();
        MyAmazon.Panel.repaint();
    }//GEN-LAST:event_BtnAdminMouseClicked


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel Background;
    private javax.swing.JLabel BtnAdmin;
    private javax.swing.JLabel BtnIden;
    private javax.swing.JLabel BtnReg;
    private javax.swing.JLabel Inicio;
    // End of variables declaration//GEN-END:variables
}
