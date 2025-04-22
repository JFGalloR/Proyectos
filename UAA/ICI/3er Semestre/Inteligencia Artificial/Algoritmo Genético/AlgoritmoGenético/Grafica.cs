using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace AlgoritmoGenético
{
    public partial class Grafica : Form
    {
        int c = 0;
        int generacion = 0;
        int min = 0;
        int max = 0;
        double presicion = 0.0;
        int l = 0;
        int pob = 0;
        int mutacion = 0;
        int cruce = 0;
        Individuo[] ind;
        Individuo[] newInd;
        Individuo[] mejores;
        Individuo padre1;
        Individuo padre2;
        Individuo hijo1;
        Individuo hijo2;
        Random r = new Random();
        


        public Grafica(int generacion, int min, int max, double presicion, int pob, int mutacion, int cruce)
        {
            this.generacion = generacion;
            this.min = min;
            this.max = max;
            this.presicion = presicion;
            this.pob = pob;
            this.mutacion = mutacion;
            this.cruce = cruce;
            l = (int) Math.Round(Math.Log(1 + (max - min) / presicion, 2));
            ind = new Individuo[pob];
            newInd = new Individuo[pob];
            mejores = new Individuo[generacion];
            InitializeComponent();
            ProcesoGenetico();
            LlenarGrafico();
            chart1.Select();
        }

        void ProcesoGenetico()
        {
            CrearPoblacion();
            ObtenerMejores();
            for (int i = 0; i < generacion-1; i++)
            {
                textBox1.Text += Environment.NewLine + "======= GENERACIÓN #" + (i + 2).ToString() + " ==============================================" + Environment.NewLine + Environment.NewLine;
                if (pob%2 == 0)
                {
                    for (int j = 0; j < pob; j += 2)
                    {
                        Seleccion();
                        Cruzamiento();
                        Mutacion();
                        newInd[j] = new Individuo(hijo1.cromosoma, l, min, max);
                        newInd[j + 1] = new Individuo(hijo2.cromosoma, l, min, max);

                        textBox1.Text += newInd[j].cromosoma + "\t" + newInd[j].x + "\t\t" + newInd[j].y + Environment.NewLine;
                        textBox1.Text += newInd[j+1].cromosoma + "\t" + newInd[j+1].x + "\t\t" + newInd[j+1].y + Environment.NewLine;

                    }
                }
                else
                {
                    for (int j = 0; j < pob-1; j += 2)
                    {
                        Seleccion();
                        Cruzamiento();
                        Mutacion();
                        newInd[j] = new Individuo(hijo1.cromosoma, l, min, max);
                        newInd[j + 1] = new Individuo(hijo2.cromosoma, l, min, max);

                        textBox1.Text += newInd[j].cromosoma + "\t" + newInd[j].x + "\t\t" + newInd[j].y + Environment.NewLine;
                        textBox1.Text += newInd[j + 1].cromosoma + "\t" + newInd[j + 1].x + "\t\t" + newInd[j + 1].y + Environment.NewLine;
                    }
                    newInd[pob-1] = new Individuo(hijo1.cromosoma, l, min, max);
                    textBox1.Text += newInd[pob-1].cromosoma + "\t" + newInd[pob - 1].x + "\t\t" + newInd[pob-1].y + Environment.NewLine;
                }
                ind = (Individuo[])newInd.Clone();
                ObtenerMejores();
            }

            Individuo hercules = new Individuo(mejores[0].cromosoma, l ,min, max);

            textBox1.Text += Environment.NewLine + "======= MEJORES INDIVIDUOS ==========================================" + Environment.NewLine + Environment.NewLine;
            textBox1.Text += Environment.NewLine + "|   GENERACIÓN E INDIVIDUO   |                X                |             ADAPTACIÓN             |" + Environment.NewLine + Environment.NewLine;

            for (int i = 0; i < generacion; i++)
            {
                textBox1.Text += i+1 + ".   " + mejores[i].cromosoma + "\t" + mejores[i].x + "\t\t" + mejores[i].y + Environment.NewLine;
                if(hercules.y < mejores[i].y)
                {
                    hercules = new Individuo(mejores[i].cromosoma, l, min, max);
                }
            }

            textBox1.Text += Environment.NewLine + "=========== MEJOR DE TODOS ========================================" + Environment.NewLine + Environment.NewLine;
            textBox1.Text +=  hercules.cromosoma + "\t" + hercules.x + "\t\t" + hercules.y + Environment.NewLine;
        }


        void CrearPoblacion() // Se crea la población inicial.
        {
            textBox1.Text += Environment.NewLine + "|         INDIVIDUO               |                   X                   |             ADAPTACIÓN             |" + Environment.NewLine + Environment.NewLine;

            textBox1.Text += "======= GENERACIÓN #1 ==============================================" + Environment.NewLine + Environment.NewLine;
            for (int i = 0; i < pob; i++)
            {
                ind[i] = new Individuo(l, min, max, r);
                textBox1.Text += ind[i].cromosoma + "\t" + ind[i].x + "\t\t" + ind[i].y + Environment.NewLine;
            }
            
        }

        void Seleccion() // Se selecciona los individuos por ruleta.
        {
            double totalY = 0.0;
            double[] prob = new double[pob];
            double selector = 0.0;
            double acumulador = 0.0;

            for(int i = 0;i < pob;i++)
            {
                totalY += ind[i].y;
            }

            for(int i = 0;i<pob;i++)
            {
                prob[i] = ind[i].y / totalY;
            }

            selector = r.NextDouble();
            for(int i = 0; i <pob;i++)
            {
                acumulador += prob[i];
                if (acumulador >= selector)
                {
                    padre1 = new Individuo(ind[i].cromosoma, l, min, max);
                    break;
                }
                
            }

            selector = r.NextDouble();
            acumulador = 0.0;

            for (int i = 0; i < pob; i++)
            {
                acumulador += prob[i];
                if (acumulador >= selector)
                {
                    padre2 = new Individuo(ind[i].cromosoma, l, min, max);
                    break;
                }
            }

        }

        void Cruzamiento() // Se realiza el cruce desde la mitad de la cadena si se cumple la probabilidad.
        {
            double auxCruce = (double)cruce / 100;
            if(r.NextDouble() <= auxCruce)
            {
                hijo1 = new Individuo(padre1.cromosoma.Substring(0,l/2) + padre2.cromosoma.Substring(l/2),l,min,max);
                hijo2 = new Individuo(padre2.cromosoma.Substring(0, l / 2) + padre1.cromosoma.Substring(l / 2), l, min, max);
            } else
            {
                hijo1 = new Individuo(padre1.cromosoma, l, min, max);
                hijo2 = new Individuo(padre1.cromosoma, l, min, max);
            }
        }

        void Mutacion() // Se muta los hijos si se cumple la probabilidad.
        {
            double auxMutacion = (double)mutacion / 100;

            if (r.NextDouble() <= auxMutacion)
            {
                int mut = r.Next(l);
                char[] aux = hijo1.cromosoma.ToCharArray();
                aux[mut] = (aux[mut]=='0')?'1':'0';
                hijo1 = new Individuo(new string(aux), l, min, max);
            }

            if (r.NextDouble() <= auxMutacion)
            {
                int mut = r.Next(l);
                char[] aux = hijo2.cromosoma.ToCharArray();
                aux[mut] = (aux[mut] == '0') ? '1' : '0';
                hijo2 = new Individuo(new string(aux), l, min, max);
            }
        }

        void ObtenerMejores()
        {
            Individuo a = new Individuo(ind[0].cromosoma, l, min, max);
            for (int i=1; i< pob; i++)
            {
                if(a.y < ind[i].y)
                {
                    a = new Individuo(ind[i].cromosoma, l, min, max);
                }
            }
            mejores[c] = new Individuo(a.cromosoma, l, min, max);
            c++;
        }

        void LlenarGrafico()
        {
            Series series = new Series("Funcion");
            for(double i = min; i<=max; i+=0.05)
            {
                series.Points.AddXY(i, funcion(i));
            }
            
            chart1.Series.Add(series);
            series.ChartType = SeriesChartType.Spline;
            series.Color = Color.Red;
            series.BorderWidth = 3;

        }
        public double funcion(double x)
        {
            return x / (1 + Math.Pow(x, 2));
        }
    }
}
