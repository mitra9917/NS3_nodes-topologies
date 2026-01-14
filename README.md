# 🌐 Hybrid Network Topology using ns-3

This project demonstrates the creation and simulation of a **Hybrid Network Topology** using **ns-3 (Network Simulator 3)**.  
The hybrid topology is formed by combining **Star ⭐, Ring 🔄, Bus 🚌, Tree 🌳, and Mesh 🕸** topologies into a single network and visualizing it using **NetAnim (nsnam)**.

---

## 🎯 Aim
To design, simulate, and visualize a hybrid network topology consisting of multiple basic topologies using ns-3.

---

## 🧠 Topologies Used
- ⭐ Star  
- 🔄 Ring  
- 🚌 Bus  
- 🌳 Tree  
- 🕸 Mesh  

**🔢 Total Number of Nodes:** 25

---

## 🛠 Tech Stack
- 💻 Programming Language: **C++**
- 📡 Simulator: **ns-3 (v3.46.1)**
- 🎥 Visualization Tool: **NetAnim (nsnam)**
- ✍️ Editor: **VS Code**
- 🖥 Platform: **macOS (Apple Silicon M2 compatible)**

---

## 📁 Project Structure
ns3-hybrid-topology/
├── scratch/
│ └── hybrid-topology.cc
├── output/
│ └── hybrid-topology.xml
├── README.md
└── .gitignore


---

## ▶️ How to Run
1. Navigate to the ns-3 directory  
2. Place `hybrid-topology.cc` inside the `scratch/` folder  
3. Run the simulation using:
./ns3 run scratch/hybrid-topology.cc


📤 Output
The simulation generates an XML file:
output/hybrid-topology.xml
This file is opened using NetAnim to visualize the hybrid topology.

👀 Visualization
The NetAnim output displays:
🔢 Node numbering (0–24)
🔗 Interconnected hybrid structure
🧩 Combination of star, ring, bus, tree, and mesh links
📸 (Screenshots of the NetAnim visualization are included in the repository)

✅ Result
A hybrid network topology with 25 nodes was successfully created, simulated, and visualized using ns-3 and NetAnim.

🏁 Conclusion
The experiment demonstrates the effective use of ns-3 for designing complex hybrid network topologies and validates correct node creation, connectivity, and visualization.

👤 Author
Shubham Kumar
🎓 Computer Science Engineering
