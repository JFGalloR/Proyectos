#==============================================================================
# :::::::::::::::::::::::::: PROYECTO FINAL. Juego "AtropellaPollos" 🐓🚗 ::: 
#============================================================================== 
#   • Elaborado por:
#       Juan Francisco Gallo Ramírez
#       Pablo Emilio Soto Parada
#----------------------------------------------------------------------------
#   • Asignatura: 
#       "Lenguajes Inteligentes"
#   • Profesor: 
#       Alejandro Padilla Díaz
#----------------------------------------------------------------------------
#   I.C.I. 5to Semestre. Diciembre 2024.
#==============================================================================
import json
import math
import random
import time
from ursina import *

#==============================================================================
# :::::::::::::::::::::::::::::::::::::::::::::::::::: VARIABLES GLOBALES :::
#==============================================================================
#____________________________________________________ Variables de pantalla ___
screen_width = 1100
screen_height = 650

#__________________________________________ Variables de estado de pantalla ___
game_screens = {'principal': 0, 'charging': 1, 'normalModeGame': 2}
game_screen = 0

#______________________ Variables de caracteristicas de juego y jugabilidad ___
plane_scale = 500
mouse_sensitivity = 2000
rotation = {'max_x': 0, 'min_x': 0, 'max_y': 0, 'min_y': 0}

speed = 0
max_speed = 1.4
max_speed_reverse = -0.50

acceleration = 0.60
acceleration_reverse = -0.50

friction = -0.40

direction_speed = 60
direction_proportion = 2 / 3

pause = False

key_pressed = False
hit = False
brake = False
started = False

view = {'first_person': 0, 'third_person': 1}
view_mode = 0
first_person = {'x': 0 ,'y': 0.76, 'z': -0.45, 
                'init_rot': (8, 0, 0), 
                'max_rot_x': 20, 'min_rot_x': -20,
                'max_rot_y': 75, 'min_rot_y': -75,
                'max_z': -0.45}
third_person = {'x': 0 ,'y': 2, 'z': -8,
                'init_rot': (4, 0, 0),
                'max_rot_x': 13, 'min_rot_x': 3.5,
                'max_rot_y': 175, 'min_rot_y': -175,
                'max_z': -8}

#_________________________________________ Variables de elementos del juego ___
pause_elements = []
controls_elements = []

number_chickens = 10
chickens_killed = None
counter = None

kart = None
walls = []
chickens = []

text_number_chickens = None
text_counter = None

kart_sound = None
kart_engine = None
kart_brake = None
hit_sound = None
chicken_sound = None

#==============================================================================
# ::::::::::::::::::::::::::::::::::::::::: GENERACIÓN DEL MENÚ PRINCIPAL :::
#==============================================================================       
def generateMainMenu():
    global text_number_chickens
    
    scene.clear()
    
    #______________________________________________ Generación de elementos ___
    #==========================================================================
    game_screen = game_screens['principal']
    
    Entity(model='quad', 
            texture='Imagenes/menu_principal.png', 
            scale=(16, 9), z=1)
    
    Button(text='Jugar',
            color=color.orange,
            highlight_color=color.gold,
            text_color=color.white,
            scale=(0.3, 0.05),
            position=(0, -0.14),
            model='quad',
            on_click = startGame)
    
    Button(text='Salir',
            color=color.red,
            highlight_color=color.gold,
            text_color=color.white,
            scale=(0.3, 0.04),
            position=(0, -0.2),
            model='quad',
            on_click = application.quit)
    
    Audio('Sonidos/chicken_wing_beat.mp3', loop=True, autoplay=False, volume=0.5).play()
    

#==============================================================================
# :::::::::::::::::::::::::::::::::::::::::::::::::::::: INICIO DEL JUEGO :::
#==============================================================================  
def startGame():
    global game_sceen, game_screens
    
    scene.clear()
    
    #____________________________________________________ Pantalla de carga ___
    #==========================================================================
    game_screen = game_screens['charging']
    Entity(parent=camera.ui,
           model='quad', 
           texture='Imagenes/pantalla_carga.png', 
           scale=(1.7, 1))
    
    #_________________________________________________ Generación del mundo ___
    #==========================================================================
    invoke(generateWorld, delay=5)

#==============================================================================
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::: FINAL DEL JUEGO :::
#==============================================================================
def endGame():
    global pause
    global counter
    global text_counter
    
    pause = True
    new_record = False
    
    mouse.visible = True
    text_counter.enabled = False
    
    #______________________________________ Se comprueba el récord guatdado ___
    #==========================================================================
    try:
        with open('Records/record.json', 'r') as file:
            data = json.load(file)
            
            if data['record'] > counter:
                new_record = True
    except (json.JSONDecodeError, FileNotFoundError):
        new_record = True
            
        
    if new_record:
        with open('Records/record.json', 'w') as file:
            json.dump({ 'record' : counter }, file, indent=4)
            
        Entity(parent=camera.ui,
               model='quad', 
               texture='Imagenes/pantalla_nuevo_record.png', 
               scale=(1.7, 1))
        Audio('Sonidos/awebo.mp3', loop=False, autoplay=False).play()
    else:
        Entity(parent=camera.ui,
               model='quad', 
               texture='Imagenes/pantalla_fin_juego.png', 
               scale=(1.7, 1))
        Audio('Sonidos/yay.mp3', loop=False, autoplay=False).play()
        
    minutes = int(counter // 60)
    seconds = int(counter % 60)
    milliseconds = int((counter - int(counter)) * 1000)
    
    #_____________________________________ Se genera el texto con el tiempo ___
    #==========================================================================
    Text(text='Tu tiempo:',
         font='Fonts/Daydream.ttf',
         color=color.orange,
         scale=1.5,
         position=(0, 0.1),
         origin=(0, 0))
    
    Text(text= f'{minutes:02}:{seconds:02}.{milliseconds:03}',
         font='Fonts/Daydream.ttf',
         text_color=color.white,
         scale=2.5,
         position=(0, 0),
         origin=(0, 0))
    
    Button(text='Reiniciar',
           color=color.orange,
           highlight_color=color.gold,
           text_color=color.white,
           scale=(0.3, 0.05),
           position=(0, -0.24),
           model='quad',
           on_click = startGame)
    
    Button(text='Salir',
           color=color.red,
           highlight_color=color.gold,
           text_color=color.white,
           scale=(0.3, 0.04),
           position=(0, -0.3),
           model='quad',
          on_click = application.quit)
    
#==============================================================================
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::: TOGGLE DE PAUSA :::
#==============================================================================           
def togglePause():
    global pause
    global pause_elements
    
    pause = not pause
    
    #___________________ Se cambia la visibilidad de los elementos de pausa ___
    #==========================================================================
    for element in pause_elements:
        element.enabled = pause
        
    if not pause:
        showControls()
        
    mouse.visible = pause
    mouse.position = (0, 0)
    
#==============================================================================
# :::::::::::::::::::::::::::::::::::::::::::: MOSTRAR CONTROLES DE JUEGO :::
#==============================================================================  
def showControls():
    global controls_elements
    
    #____________________________________________ Se muestran los controles ___
    #==========================================================================
    for element in controls_elements:
        current_color = element.color
        new_color = color.rgba(current_color.r, current_color.g, current_color.b, 1)
        element.color = new_color
        
    #__________________________________________ Se desvanecen los controles ___
    #==========================================================================
    invoke(fade_out_controls, delay=2)
  
#==============================================================================
# ::::::::::::::::::::::::::::::::::::::::::: FADE OUT PARA LOS CONTROLES :::
#==============================================================================       
def fade_out_controls():
    global controls_elements
    
    #__________________________________________ Se desvanecen los controles ___
    #==========================================================================
    for element in controls_elements:
        current_color = element.color
        new_color = color.rgba(current_color.r, current_color.g, current_color.b, 0)
        element.animate_color(new_color, duration=1, curve=curve.linear)

#==============================================================================
# ::::::::::::::::::::::::::::::::: GENERACION DE LOS ELEMENTOS DEL MUNDO :::
#==============================================================================   
def generateWorld():
    global game_screen, game_screens
    global kart
    global walls
    global chickens
    global kart_sound
    global kart_engine
    global kart_brake
    global chicken_sound
    global hit_sound
    global text_number_chickens
    global text_counter
    global pause
    global started
    global pause_elements
    global controls_elements
    global chickens_killed
    global counter
    
    #_____________________________ Inicialización de las variables globales ___
    #==========================================================================
    pause = False
    started = False
    pause_elements.clear()
    controls_elements.clear()
    walls.clear()
    chickens.clear()
    chickens_killed = 0
    counter = 0
    
    number_trees = 40
    number_plants = 65
    number_rocks = 40
    
    scene.clear()
    
    mouse.visible = False
    
    game_screen = game_screens['normalModeGame']
    
    #____________________________________________ Generación de indicadores ___
    #==========================================================================
    Entity(parent=camera.ui,
           model='quad',
           texture='Imagenes/pollo.png',
           scale=(0.09, 0.09),
           position=(0.56, 0.44),
           origin=(0, 0),)
    
    text_number_chickens = Text(text='0',
                                font='Fonts/Daydream.ttf',
                                color=color.yellow,
                                scale=1.9,
                                position=(0.65, 0.45),
                                origin=(0, 0))
    
    Text(text='/' + str(number_chickens),
         font='Fonts/Daydream.ttf',
         color=color.red,
         scale=1.9,
         position=(0.76, 0.45),
         origin=(0, 0))
    
    text_counter = Text(text='00:00',
                        font='Fonts/Daydream.ttf',
                        color=color.orange,
                        scale=1.9,
                        position=(0, 0.45),
                        origin=(0, 0))
    
    #__________________________________________________ Generación del kart ___
    #==========================================================================
    kart = Entity(model = 'Entidades/kart.obj', 
                  texture = 'Texturas/kart.png',
                  scale = 1,
                  collider = 'box')
    
    #____________________________________ Generación de elementos de sonido ___
    #==========================================================================
    hit_sound = Audio('Sonidos/golpe.mp3', loop=False, autoplay=False)
    kart_sound = Audio('Sonidos/gokart_aceleracion.mp3', loop=False, autoplay=False)
    kart_engine = Audio('Sonidos/gokart_motor.mp3', loop=False, autoplay=False)
    kart_brake = Audio('Sonidos/gokart_freno.mp3', loop=False, autoplay=False)
    chicken_sound = Audio('Sonidos/pollo.mp3', loop=False, autoplay=False)
    
    wall_thickness = 1
    wall_height = 6

    #_______________________________ Generación del cielo, el plano y muros ___
    #==========================================================================
    Sky()
    ground = Entity(model = 'plane', 
                    scale = plane_scale, 
                    texture = 'grass',
                    texture_scale=(5, 5), 
                    collider = 'mesh')
    
    wall_1 = Entity(model = 'cube', 
                    scale = (plane_scale, wall_height, wall_thickness),
                    texture = 'Texturas/roca_4.jpg',
                    texture_scale=(20, 0.5),
                    position = (0, wall_height / 2, plane_scale / 2),
                    collider = 'box')
    
    wall_2 = Entity(model = 'cube', 
                    scale = (wall_thickness, wall_height, plane_scale),
                    texture = 'Texturas/roca_4.jpg',
                    texture_scale=(20, 0.5),
                    position = (plane_scale / 2, wall_height / 2, 0),
                    collider = 'box')
    
    wall_3 = Entity(model = 'cube', 
                    scale = (plane_scale, wall_height, wall_thickness),
                    texture = 'Texturas/roca_4.jpg',
                    texture_scale=(20, 0.5),
                    position = (0, wall_height / 2, -plane_scale / 2),
                    collider = 'box')
    
    wall_4 = Entity(model = 'cube', 
                    scale = (wall_thickness, wall_height, plane_scale),
                    texture = 'Texturas/roca_4.jpg',
                    texture_scale=(20, 0.5),
                    position = (-plane_scale / 2, wall_height / 2, 0),
                    collider = 'box')
    
    walls.append(wall_1)
    walls.append(wall_2)
    walls.append(wall_3)
    walls.append(wall_4)
    
    #________________________________________________ Generación de árboles ___
    #==========================================================================
    for i in range(number_trees):
        random_scale = random.randint(1, 5) / 10
        random_pos_z = random.randint(-245, 245)
        random_pos_x = random.randint(-245, 245)
        random_rotation = random.randint(0, 360)
        
        Entity(
            model='Entidades/arbol.obj',
            texture='Texturas/tronco.png',
            scale=random_scale, 
            position=(random_pos_x, 0, random_pos_z),
            rotation_y = random_rotation,
            collider = 'mesh'
        )
        
        
        Entity(
            model='Entidades/hojas.obj',
            texture='Texturas/hoja.png',
            scale=random_scale,
            position=(random_pos_x, 0, random_pos_z),
            rotation_y = random_rotation,
            alpha_mask='Texturas/mascara_hoja.png'
        )
    
    #________________________________________________ Generación de plantas ___
    #==========================================================================
    for i in range(number_plants):
        random_scale = random.randint(1, 4) / 10
        random_pos_z = random.randint(-245, 245)
        random_pos_x = random.randint(-245, 245)
        random_rotation = random.randint(0, 360)
        
        Entity(
            model='Entidades/palma.obj',
            texture='Texturas/tallo_palma.jpg',
            scale = random_scale, 
            position=(random_pos_x, 0, random_pos_z),
            rotation_y = random_rotation
        )
        
        Entity(
            model='Entidades/palma.obj',
            texture='Texturas/hojas_palma.png',
            scale = random_scale, 
            position=(random_pos_x, 0, random_pos_z),
            rotation_y = random_rotation
        )
        
    for i in range(number_plants):
        random_scale = random.randint(1, 5) / 10
        random_pos_z = random.randint(-245, 245)
        random_pos_x = random.randint(-245, 245)
        random_rotation = random.randint(0, 360)
        
        Entity(
            model='Entidades/planta.obj',
            texture='Texturas/planta_1.jpg',
            scale = random_scale, 
            position=(random_pos_x, 0, random_pos_z),
            rotation_y = random_rotation
        )
    
    for i in range(number_plants):
        random_scale = random.randint(1, 5) / 10
        random_pos_z = random.randint(-245, 245)
        random_pos_x = random.randint(-245, 245)
        random_rotation = random.randint(0, 360)
        
        Entity(
            model='Entidades/planta.obj',
            texture='Texturas/planta_2.jpg',
            scale = random_scale, 
            position=(random_pos_x, 0, random_pos_z),
            rotation_y = random_rotation
        )
    
    for i in range(number_plants):
        random_scale = random.randint(1, 5) / 10
        random_pos_z = random.randint(-245, 245)
        random_pos_x = random.randint(-245, 245)
        random_rotation = random.randint(0, 360)
        
        Entity(
            model='Entidades/planta.obj',
            texture='Texturas/planta_3.jpg',
            scale = random_scale, 
            position=(random_pos_x, 0, random_pos_z),
            rotation_y = random_rotation
        )
        
    #_________________________________________________ Generación de rocas ___
    #==========================================================================
    for i in range(number_rocks):
        random_scale = random.randint(3, 40) / 10
        random_pos_z = random.randint(-245, 245)
        random_pos_x = random.randint(-245, 245)
        random_rotation = random.randint(0, 360)
        
        rock = ['roca_1', 'roca_2', 'roca_3', 'roca_4', 'roca_5']
        
        Entity(
            model='Entidades/s.obj',
            texture= 'Texturas/' + rock[random.randint(0, 4)] + '.jpg',
            scale = random_scale, 
            position=(random_pos_x, -1, random_pos_z),
            rotation_y = random_rotation,
            collider='mesh'
        )
        
    #_________________________________________________ Generación de pollos ___
    #==========================================================================
    for i in range(number_chickens):
        random_scale = random.randint(1, 2)
        random_pos_z = random.randint(-245, 245)
        random_pos_x = random.randint(-245, 245)
        random_rotation = random.randint(0, 360)
        
        chicken = Entity(
            model='Entidades/pollo.obj',
            texture= 'Texturas/pollo.png',
            scale = 1.2, 
            position=(random_pos_x, 0, random_pos_z),
            rotation_y = random_rotation,
            collider = 'box'
        )
        
        chickens.append(chicken)
        

    #_________________________________________________ Generación de cabaña ___
    #==========================================================================
    for i in range(1):
        random_scale = random.randint(1, 2)
        random_pos_z = random.randint(-245, 245)
        random_pos_x = random.randint(-245, 245)
        
        Entity(
            model='Entidades/cabaña.obj',
            texture= 'Texturas/cabaña.jpg',
            scale = 0.4, 
            position=(random_pos_x, 0, random_pos_z),
            collider='box'
        )
        
    #__________________________________________________ Ubicación de cámara ___
    #==========================================================================
    camera.parent = kart
    camera.position = third_person['init_rot']
    camera.look_at(kart)
    changeView(view['third_person'])
    
    #_____________________________________ Generación de elementos de pausa ___
    #==========================================================================
    background = Entity(parent=camera.ui,
                        model='quad',
                        texture='Imagenes/pantalla_pausa.png',
                        scale=(1.7, 1),
                        enabled=False)
    
    btn_1 = Button(text='Continuar',
                   color=color.orange,
                   highlight_color=color.gold,
                   text_color=color.white,
                   scale=(0.3, 0.05),
                   position=(0, 0.1),
                   model='quad',
                   on_click = togglePause,
                   enabled=False)
    
    btn_2 = Button(text='Reiniciar',
                   color=color.orange,
                   highlight_color=color.gold,
                   text_color=color.white,
                   scale=(0.3, 0.05),
                   position=(0, 0.03),
                   model='quad',
                   on_click = startGame,
                   enabled=False)
    
    btn_3 = Button(text='Salir',
                   color=color.red,
                   highlight_color=color.gold,
                   text_color=color.white,
                   scale=(0.3, 0.04),
                   position=(0, -0.3),
                   model='quad',
                   on_click = application.quit,
                   enabled=False)
    
    
    pause_elements.append(background)
    pause_elements.append(text)
    pause_elements.append(btn_1)
    pause_elements.append(btn_2)
    pause_elements.append(btn_3)
    
    #_______________________________ Generación de indicadores de controles ___
    #==========================================================================
    ctrl_1 = Text(text='W, S',
                  font='Fonts/Daydream.ttf',
                  color=color.black,
                  scale=1.3,
                  position=(-0.78, 0),
                  origin=(0, 0))
    
    ctrl_1D = Text(text='Acelerar / Desacelerar',
                   font='Fonts/Daydream.ttf',
                   color=color.white,
                   scale=0.7,
                   position=(-0.53, 0),
                   origin=(0, 0))
    
    ctrl_2 =  Text(text='A, D',
                   font='Fonts/Daydream.ttf',
                   color=color.black,
                   scale=1.3,
                   position=(-0.78, -0.05),
                   origin=(0, 0))
    
    ctrl_2D =  Text(text='Control de dirección',
                    font='Fonts/Daydream.ttf',
                    color=color.white,
                    scale=0.7,
                    position=(-0.55, -0.05),
                    origin=(0, 0))
    
    ctrl_3 = Text(text='V',
                  font='Fonts/Daydream.ttf',
                  color=color.black,
                  scale=1.3,
                  position=(-0.78, -0.1),
                  origin=(0, 0))
    
    ctrl_3D =   Text(text='Cambiar vista',
                     font='Fonts/Daydream.ttf',
                     color=color.white,
                     scale=0.7,
                     position=(-0.605, -0.1),
                     origin=(0, 0))
    
    ctrl_4 =   Text(text='P',
                    font='Fonts/Daydream.ttf',
                    color=color.black,
                    scale=1.3,
                    position=(-0.78, -0.15),
                    origin=(0, 0))
    
    ctrl_4D =  Text(text='Pausa',
                    font='Fonts/Daydream.ttf',
                    color=color.white,
                    scale=0.7,
                    position=(-0.665, -0.15),
                    origin=(0, 0))
    
    controls_elements.append(ctrl_1)
    controls_elements.append(ctrl_1D)
    controls_elements.append(ctrl_2)
    controls_elements.append(ctrl_2D)
    controls_elements.append(ctrl_3)
    controls_elements.append(ctrl_3D)
    controls_elements.append(ctrl_4)
    controls_elements.append(ctrl_4D)
    
    
        
        
#==============================================================================
# ::::::::::::::::::::::::::::::::::::::::::: COMPORTAMIENTO DE LA CÁMARA :::
#==============================================================================       
def cameraBehavior():
    global mouse_sensitivity
    global rotation
    
    #______________________________ Movimiento de cámara en tercera persona ___
    #==========================================================================
    if view_mode == view['third_person']:
        camera.z = math.cos(math.radians(camera.rotation_y)) * third_person['max_z']
        camera.x = math.sin(math.radians(camera.rotation_y)) * third_person['max_z']
    
    #___________________________________________________ Rotación de cámara ___
    #==========================================================================
    camera.rotation_x = clamp(camera.rotation_x -mouse.y * mouse_sensitivity * time.dt, rotation['min_x'], rotation['max_x'])
    camera.rotation_y = clamp(camera.rotation_y + mouse.x * mouse_sensitivity * time.dt, rotation['min_y'], rotation['max_y'])
    mouse.position = (0, 0)
    
    
#==============================================================================
# ::::::::::::::::::::::::::::::::::::::::::::::: COMPORTAMIENTO DEL KART :::
#==============================================================================
def kartBehavior():
    global kart
    global speed, max_speed, max_speed_reverse
    global acceleration, acceleration_reverse, friction
    global direction_speed, direction_proportion
    global hit
    global brake
    global started
    
    #___________________________________ Velocidad del vector de movimiento ___
    #==========================================================================
    acc = 0
        
    if held_keys['w'] and held_keys['s']:
        if speed > 0:
            acc = acceleration_reverse
        elif speed < 0:
            acc = acceleration
        elif speed == 0:
            acc = 0
    elif held_keys['w']:
        acc = acceleration
        if not kart_sound.playing:
            kart_sound.play()
        brake = False
    elif held_keys['s']:
        acc = acceleration_reverse
        
        if not kart_sound.playing:
            kart_sound.play()
        if speed > 0 and not brake and not kart_brake.playing:
            kart_brake.play()
            brake = True

    if speed != 0 and not started:
        started = True
        showControls()
    if speed > 0 or speed == 0 and acc > 0:
        speed = clamp(speed + (acc + friction) * time.dt, 
                      0, 
                      max_speed)
    elif speed < 0 or speed == 0 and acc < 0:
        speed = clamp(speed + (acc - friction) * time.dt, 
                      max_speed_reverse, 
                      0)
    
    #___________________________________ Dirección del vector de movimiento ___
    #==========================================================================
    if held_keys['a'] and speed != 0:
        kart.rotation_y += (1 if speed > 0 else -1) * (max_speed - direction_proportion * abs(speed)) * -direction_speed * time.dt
    if held_keys['d'] and speed != 0:
        kart.rotation_y += (1 if speed > 0 else -1) * (max_speed - direction_proportion * abs(speed)) * direction_speed * time.dt
    
    #________________________________________ Concretar posición del objeto ___
    #==========================================================================
    if kart.intersects().hit:                        #------ Mecánica de golpe.
        speed = 0
        kart.z *= 0.999
        kart.x *= 0.999
        
        if not hit and not hit_sound.playing:
            hit_sound.play()
            hit = True
    else:                                            #------ Movimiento normal.
        kart.z += math.cos(math.radians(kart.rotation_y)) * speed
        kart.x += math.sin(math.radians(kart.rotation_y)) * speed
        hit = False
        
    if not kart_sound.playing and not kart_engine.playing:
        kart_engine.play()
        
        
def chickenBehavior():
    global text_chichickens_killed, chickens_killed
    
    for chicken in chickens:
        if chicken.intersects().hit:
            chickens_killed += 1
            text_number_chickens.text = str(chickens_killed)
            chicken_sound.play()
            chicken.enabled = False
            chickens.remove(chicken)
    
#==============================================================================
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::: CAMBIO DE VISTA :::
#==============================================================================
def changeView(mode):
    global view_mode, view
    global max_rotation_x, max_rotation_y
    
    #_____________________________________________ Vista en primera persona ___
    #==========================================================================
    if mode == view['first_person']:
        camera.rotation = first_person['init_rot']
        camera.x = first_person['x']
        camera.y = first_person['y']
        camera.z = first_person['z']
        rotation['max_x'] = first_person['max_rot_x']
        rotation['min_x'] = first_person['min_rot_x']
        rotation['max_y'] = first_person['max_rot_y']
        rotation['min_y'] = first_person['min_rot_y']
        view_mode = view['first_person']
    #_____________________________________________ Vista en tercera persona ___
    #==========================================================================
    elif mode == view['third_person']:
        camera.rotation = third_person['init_rot']
        camera.x = third_person['x']
        camera.y = third_person['y']
        camera.z = third_person['z']
        rotation['max_x'] = third_person['max_rot_x']
        rotation['min_x'] = third_person['min_rot_x']
        rotation['max_y'] = third_person['max_rot_y']
        rotation['min_y'] = third_person['min_rot_y']
        view_mode = view['third_person']
    
#==============================================================================
# ::::::::::::::::::::::::::::::::::: ACTUALIZACIÓN DE ELEMENTOS EN JUEGO :::
#==============================================================================
def normalModeGameUpdate():
    global kart
    global pause
    global mouse_sensitivity
    global key_pressed
    global counter
    global text_counter
    global number_chickens
    global chickens_killed
    
    #__________________________________ Actualización de elementos en juego ___
    #==========================================================================
    if not pause:
        kartBehavior()
        cameraBehavior()
        chickenBehavior()
        
        if held_keys['v'] and not key_pressed:
            changeView(view['first_person'] if view_mode == view['third_person'] else view['third_person'])
            key_pressed = True
            
        if not held_keys['v']:
            key_pressed = False
            
        if held_keys['p']:
            togglePause()
            
        if started:
            counter += time.dt
            minutes = int(counter // 60)
            seconds = int(counter % 60)
            milliseconds = int((counter - int(counter)) * 1000)
            text_counter.text = f'{minutes:02}:{seconds:02}'
        
        if chickens_killed == number_chickens:
            endGame()

#==============================================================================
# :::::::::::::::::::::::::::::::::::::::::::: ACTUALIZACIÓN DE ELEMENTOS :::
#==============================================================================
def update():
    global walls
    global kart
    global game_sceen, game_screens
    
    #___________________________________________ Actualización de elementos ___
    #==========================================================================
    if game_screen == game_screens['principal'] or game_screen == game_screens['charging']:
        a1 = 0
    elif game_screen == game_screens['normalModeGame']:
        normalModeGameUpdate()
        

#==============================================================================
# --------------------------------------------- COMIENZO DE LA APLICACIÓN ---
#==============================================================================

#_____________________________________________ Generación del motor gráfico ___
#==============================================================================
game = Ursina(size=(screen_width, screen_height),
              window_type='onscreen',
              development_mode=False,
              title='AtropellaPollos',
              icon='Imagenes/favicon.ico')

window.always_on_top = True 

#____________________________________________ Generación del menú principal ___
#==============================================================================
generateMainMenu()

#________________________________________________ Arranque de la aplicación ___
#==============================================================================
game_screen = game_screens['principal']
game.run()





        
    
        
