package MyAmazon;

import MyAmazon.Fonts.Fonts;
import java.awt.Color;

public class InicioCompras extends javax.swing.JPanel {

    Compras c;

    public InicioCompras(Compras c) {
        initComponents();
        this.c = c;
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        Label4 = new javax.swing.JLabel();
        Label3 = new javax.swing.JLabel();
        Label2 = new javax.swing.JLabel();
        Label1 = new javax.swing.JLabel();
        Background = new javax.swing.JLabel();

        setBackground(new java.awt.Color(255, 255, 255));
        setPreferredSize(new java.awt.Dimension(1150, 650));
        setLayout(null);

        Label4.setBackground(new java.awt.Color(255, 255, 255));
        Label4.setFont(new Fonts().setFonts(Fonts.EMBER_HE, 0, 28));
        Label4.setForeground(new java.awt.Color(0, 19, 34));
        Label4.setText("Y más...");
        Label4.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                Label4MouseMoved(evt);
            }
        });
        Label4.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                Label4MouseClicked(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                Label4MouseExited(evt);
            }
        });
        add(Label4);
        Label4.setBounds(900, 410, 250, 60);

        Label3.setBackground(new java.awt.Color(255, 255, 255));
        Label3.setFont(new Fonts().setFonts(Fonts.EMBER_HE, 0, 28));
        Label3.setForeground(new java.awt.Color(130, 184, 161));
        Label3.setText("Moda");
        Label3.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                Label3MouseMoved(evt);
            }
        });
        Label3.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                Label3MouseClicked(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                Label3MouseExited(evt);
            }
        });
        add(Label3);
        Label3.setBounds(830, 310, 220, 60);

        Label2.setBackground(new java.awt.Color(255, 255, 255));
        Label2.setFont(new Fonts().setFonts(Fonts.EMBER_HE, 0, 27));
        Label2.setForeground(new java.awt.Color(62, 175, 255));
        Label2.setText("Alimentos y Bebidas");
        Label2.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                Label2MouseMoved(evt);
            }
        });
        Label2.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                Label2MouseClicked(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                Label2MouseExited(evt);
            }
        });
        add(Label2);
        Label2.setBounds(740, 210, 280, 50);

        Label1.setFont(new Fonts().setFonts(Fonts.EMBER_HE, 0, 28));
        Label1.setForeground(new java.awt.Color(255, 192, 0));
        Label1.setText("Electrodomésticos");
        Label1.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                Label1MouseMoved(evt);
            }
        });
        Label1.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                Label1MouseClicked(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                Label1MouseExited(evt);
            }
        });
        add(Label1);
        Label1.setBounds(670, 100, 270, 60);

        Background.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/Background.png"))); // NOI18N
        add(Background);
        Background.setBounds(0, 0, 1150, 570);
    }// </editor-fold>//GEN-END:initComponents

    private void Label1MouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_Label1MouseClicked
        c.agregarProductos("WHERE  categoria = 'Electrodomésticos'");
    }//GEN-LAST:event_Label1MouseClicked

    private void Label2MouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_Label2MouseClicked
        c.agregarProductos("WHERE  categoria = 'Alimentos y Bebidas'");
    }//GEN-LAST:event_Label2MouseClicked

    private void Label3MouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_Label3MouseClicked
        c.agregarProductos("WHERE  categoria = 'Ropa y Accesorios'");
    }//GEN-LAST:event_Label3MouseClicked

    private void Label4MouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_Label4MouseClicked
        c.agregarProductos("");
    }//GEN-LAST:event_Label4MouseClicked

    private void Label1MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_Label1MouseExited
        Label1.setForeground(new Color(255, 192, 0));
    }//GEN-LAST:event_Label1MouseExited

    private void Label1MouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_Label1MouseMoved
        Label1.setForeground(new Color( 255, 223, 127));
    }//GEN-LAST:event_Label1MouseMoved

    private void Label2MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_Label2MouseExited
        Label2.setForeground(new Color(62, 175, 255));
    }//GEN-LAST:event_Label2MouseExited

    private void Label2MouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_Label2MouseMoved
        Label2.setForeground(new Color(183, 226, 255));
    }//GEN-LAST:event_Label2MouseMoved

    private void Label3MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_Label3MouseExited
        Label3.setForeground(new Color(130, 184, 161));
    }//GEN-LAST:event_Label3MouseExited

    private void Label3MouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_Label3MouseMoved
        Label3.setForeground(new Color(209, 229, 220));
    }//GEN-LAST:event_Label3MouseMoved

    private void Label4MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_Label4MouseExited
        Label4.setForeground(new Color(0, 19, 34));
    }//GEN-LAST:event_Label4MouseExited

    private void Label4MouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_Label4MouseMoved
        Label4.setForeground(new Color(0, 92, 168));
    }//GEN-LAST:event_Label4MouseMoved


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel Background;
    private javax.swing.JLabel Label1;
    private javax.swing.JLabel Label2;
    private javax.swing.JLabel Label3;
    private javax.swing.JLabel Label4;
    // End of variables declaration//GEN-END:variables
}
