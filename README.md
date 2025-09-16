# 🏟️ IoT Smart Court – Passa Bola  

Projeto de IoT desenvolvido para a Sprint do **Passa a Bola** na disciplina de **Edge Computing and Computer Systems** da FIAP.  

---

## 📝 Descrição do Projeto  
Este projeto implementa uma solução de **quadra inteligente** que detecta ocupação, temperatura e umidade em tempo real.  

Com o uso do **ESP32**, criamos um protótipo que simula:  
- 📡 **Detecção de presença** com sensor PIR;  
- 🌡️ **Medição de temperatura e umidade** com sensor DHT22;  
- 🖥️ **Exibição local** em display OLED I2C;  
- 🎛️ **Controle manual** de início/fim de treino via botão;  
- 🖧 **Saída de dados em JSON** pelo Serial Monitor para futura integração com servidor (HTTP/MQTT).  

Essa solução apoia atletas, gestoras e patrocinadores ao permitir que dados sejam coletados automaticamente e integrados ao ecossistema **Passa a Bola**, promovendo maior transparência e engajamento.  

---

## 🎯 Escopo  
- Protótipo no **ESP32** com sensores PIR + DHT22 + OLED I2C + Botão;  
- Simulação no **Wokwi**, pronta para migração para hardware real;  
- Integração opcional futura com **Node-RED / MQTT** para dashboards em tempo real.  

---

## ✅ Objetivos Entregáveis  
- Firmware funcional para ESP32 (código-fonte em Arduino/C++);  
- Arquivo **diagram.json** para simulação no Wokwi;  
- Arquivo **libraries.txt** com bibliotecas necessárias;  
- README com instruções de uso.  

---

## 🏆 Critérios de Aceitação  

### Requisitos Obrigatórios  
- O **PIR** registra presença → quadra é exibida como *ocupada*;  
- O **botão** alterna manualmente entre *livre* e *ocupada*;  
- O **DHT22** retorna temperatura e umidade legíveis;  
- O **OLED** exibe status + condições ambientais;  
- O **Serial Monitor** mostra saída em JSON.  

### Requisito Opcional  
- Integração MQTT/HTTP enviando dados para servidor em tempo real.  

---

## 🏗️ Arquitetura Proposta  

```
[Atletas/Quadra]
   └── ESP32
         ├── PIR Sensor (ocupação)
         ├── DHT22 (temperatura/umidade)
         ├── Botão (controle do treino)
         └── OLED Display (feedback local)
               ↓
         Serial Monitor (JSON)
         → Integração futura com Servidor/Node-RED
```

---

## 🧰 Componentes Utilizados  

### Hardware (Simulação no Wokwi)  
- ESP32 DevKit v1  
- Sensor PIR (detecção de movimento)  
- Sensor DHT22 (umidade/temperatura)  
- OLED 128x64 I2C  
- Botão (Push Button)  
- Jumpers virtuais  

### Bibliotecas  
- `Adafruit SSD1306`  
- `Adafruit GFX`  
- `DHT sensor library`  

---

## 🛠️ Recursos Necessários  

- **Wokwi** (simulação online gratuita)  
- **Arduino IDE** (opcional, para rodar em hardware real)  
- Navegador moderno (para acessar Wokwi)  

---

## ▶️ Instruções de Uso  

### 1) Simulação no Wokwi  
1. Abra [Wokwi ESP32 Project](https://wokwi.com/projects/442216324171271169).  
2. Substitua os arquivos:  
   - `diagram.json` (circuito)  
   - `sketch.ino` (código principal)  
   - `libraries.txt` (dependências)  
3. Clique em **Start Simulation** ▶️  
4. Abra o **Serial Monitor** e veja os dados em JSON.  
5. Veja no **OLED** as informações da quadra em tempo real.  

### 2) Exemplo de Saída JSON  
```json
{
  "quadra": "Quadra01",
  "status": "ocupada",
  "temperatura": 27.5,
  "umidade": 62,
  "presenca": 1,
  "treinoAtivo": 0
}
```

---

## 👥 Integrantes do Grupo  

- Matheus von Koss Wildeisen - RM: 561539
- Ana Clara Rocha de Oliveira – RM: 564298
- Deivid ruan Marques – RM: 566356
- Felipe Cordeiro - RM: 566518

---

## 🚀 Futuras Evoluções  
- Integração com **Mosquitto MQTT Broker**;  
- Dashboard em **Node-RED / Grafana**;  
- Conexão com **Plataforma Passa a Bola** para exibição em mapas.  

---

## 📝 Licença  
Projeto acadêmico desenvolvido para a disciplina de **Engenharia de Software – Edge Computing & Computer Systems (FIAP)**.  
