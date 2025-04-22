import java.awt.Color;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.CategoryPlot;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.chart.renderer.category.BarRenderer;
import org.jfree.chart.renderer.category.StandardBarPainter;
import org.jfree.data.category.CategoryDataset;
import org.jfree.data.category.DefaultCategoryDataset;

public class GraficaBarras extends JFrame {
    String dBase = "Data";
    String table = "Poblacion";
    int cGen;
    List<String>lisEst = new ArrayList<>();
    CategoryPlot plot ;
    BarRenderer renderer ;
    
    public GraficaBarras(String appTitle, String dBase, String table, int cGen, List<String>lisEst) {
        super(appTitle);
        this.dBase = dBase;
        this.table = table;
        this.cGen = cGen;
        this.lisEst.addAll(lisEst);
        setIconImage(new ImageIcon(getClass().getResource("/recursos/icono2.png")).getImage());
        // Create Dataset  
        CategoryDataset dataset = createDataset();

        //Create chart  
        JFreeChart chart = ChartFactory.createBarChart(
                "Gráfica de Población", //Chart Title  
                "Estado", // Category axis  
                "Población", // Value axis  
                dataset,
                PlotOrientation.VERTICAL,
                true, true, false
        );
        plot = (CategoryPlot) chart.getPlot();
        renderer = (BarRenderer) plot.getRenderer();
        renderer.setBarPainter(new StandardBarPainter());

        switch(cGen)
        {
            case 0:
                renderer.setSeriesPaint(0, new Color(0,50,200));
                break;
            case 1:
                renderer.setSeriesPaint(0, new Color(215,50,150));
                break;
            case 2:
                renderer.setSeriesPaint(0, new Color(0,50,200));
                renderer.setSeriesPaint(1, new Color(215,50,150));
                break;
        }

        ChartPanel panel = new ChartPanel(chart);
        setContentPane(panel);
        setLocationRelativeTo(null);
    }

    private CategoryDataset createDataset() {
        DefaultCategoryDataset dataset = new DefaultCategoryDataset();
        try {
            String jdbcUrl = "jdbc:mariadb://localhost:3306";
            String username = "root";
            String password = "";
            Connection conn;

            conn = DriverManager.getConnection(jdbcUrl, username, password);
            Statement stmt = conn.createStatement();
            ResultSet rs;
            stmt.executeUpdate("USE " + dBase + ";");
            for (String est : lisEst) {

                if (cGen == 0 || cGen == 2) {
                    rs = stmt.executeQuery("SELECT COUNT(*) FROM " + table + " WHERE genero = 'H' AND estado = '" + est + "';");
                    rs.next();
                    dataset.addValue(rs.getInt(1), "Hombres", est);
                }
                if (cGen == 1 || cGen == 2) {
                    rs = stmt.executeQuery("SELECT COUNT(*) FROM " + table + " WHERE genero = 'M' AND estado = '" + est + "';");
                    rs.next();
                    dataset.addValue(rs.getInt(1), "Mujeres", est);
                }
            }
        } catch (SQLException ex) {
            JOptionPane.showMessageDialog(this, "Ocurrio una excepción.", "Base de Datos", JOptionPane.ERROR_MESSAGE);
        }
        return dataset;
    }
}
