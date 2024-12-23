
## Přehled projektu

Balog OS je projekt vlastního operačního systému, jehož cílem je vytvořit lehký, jednoduchý a efektivní systém zaměřený na fyzický hardware. Primární filozofií je postupný vývoj od základní funkcionality (klávesnice, shell) až po komplexnější funkce, jako je grafické uživatelské rozhraní (GUI) a podpora ovladačů.

## Obsah

- [Architektura](#architektura)
- [Požadavky na hardware](#požadavky-na-hardware)
- [Cíle projektu](#cíle-projektu)
- [Klíčové komponenty](#klíčové-komponenty)
- [Technické detaily](#technické-detaily)
- [Budoucí rozšíření](#budoucí-rozšíření)
- [Struktura skriptů](#struktura-skriptů)
- [Dokumentace](#dokumentace)
- [Licence](#licence)

## Architektura

### Cílová platforma

- **Architektura**: x86_64 (moderní 64bitové procesory AMD a Intel)
- **Optimalizace**: Primárně pro fyzický hardware, sekundárně pro virtualizační platformy (např. VirtualBox, QEMU).

### Bootovací mechanika

- **Bootloader**: GRUB (Grand Unified Bootloader) pro jednoduché zavádění systému.
- **Paměťová správa**: Základní podpora při zavádění (stránkování, segmentace).

## Požadavky na hardware

### Minimální požadavky

- **CPU**: Dvoujádrový procesor s podporou 64 bitů.
- **RAM**: 512 MB (pro základní funkce OS).
- **Disk**: 1–2 GB pro systém s jednoduchým GUI.

### Doporučené požadavky

- **CPU**: Čtyřjádrový nebo lepší procesor.
- **RAM**: 2–4 GB.
- **Disk**: 10 GB (včetně prostoru pro aplikace a data).

## Cíle projektu

### Fáze 1: Základní funkčnost

- Funkce klávesnice: Detekce vstupu uživatele a přenos dat do systému.
- Nastavení údajů uživatele: Možnost zadat jméno, heslo a vytvořit uživatelský účet.
- Shell: Jednoduché textové rozhraní pro spouštění příkazů.

### Fáze 2: Rozšíření funkcí

- Souborový systém: Implementace jednoduchého souborového systému (např. FAT32 nebo vlastní).
- Správa uživatelů: Přihlašování a správa uživatelských účtů.
- Základní GUI: Jednoduché grafické rozhraní s pozadím a ikonami podobné XFCE nebo KDE Plasma.

### Fáze 3: Pokročilé funkce

- Multitasking: Správa procesů a vláken.
- Ovladače: Podpora hardwaru, jako jsou grafické karty (VESA framebuffer, OpenGL).
- Kompatibilita: Experimentální podpora spouštění .exe souborů (např. pomocí Wine).

## Klíčové komponenty

### Kernel (jádro)

- **Typ**: Monolitické jádro.
- **Funkce**: Správa paměti, procesů, souborových operací a vstupních/výstupních zařízení.

### Shell

- **Vlastnosti**:
  - Interpret příkazů.
  - Možnost navigace v souborovém systému.
  - Základní příkazy (např. ls, cd, mkdir).

### Sou ```markdown
## Souborový systém

- **Cíl**: Začlenit jednoduchý souborový systém (např. FAT32) pro základní operace s daty.

### Grafické uživatelské rozhraní (GUI)

- **Základ**: Framebuffer (pro jednoduché vykreslování pixelů na obrazovku).
- **Dlouhodobý cíl**: Podpora OpenGL nebo jiných grafických API.

## Technické detaily

### Správa paměti

- Podpora stránkování a virtuální paměti.
- Oddělení kernel space a user space.

### Přerušení

- Nastavení tabulky IDT (Interrupt Descriptor Table).
- Podpora pro hardwarová i softwarová přerušení.

### Hardwarová podpora

- **Vstupní zařízení**: Podpora PS/2 a USB klávesnic a myší.
- **Grafika**: Základní podpora VESA pro framebuffer.
- **Disky**: Podpora AHCI (pro SATA disky).

## Budoucí rozšíření

- **Podpora sítě**: Implementace TCP/IP stacku pro komunikaci.
- **Pokročilé GUI**: Možnost spouštění aplikací ve vlastním grafickém prostředí.
- **Virtualizace**: Optimalizace pro běh na virtualizačních platformách.
