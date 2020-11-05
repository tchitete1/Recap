# Recap

Recap is a Command-Line program written in C that recovers "deleted" JPGs from a disk image.

## Description

The program works by iterating through the contents of a memory card, scanning for JPG "signatures"–patterns of bytes which demarcate the start of JPGs.
Upon finding a signature, Recap creates a new JPG and begins writing bytes from the memory card to the newly created file until another signature is found.
Thereafter, the program closes the currently open JPG, creates another and then continues the image recovery process.

## Getting Started

### Installation

1. Install the Recap archive by downloading [```Recap-master.zip```](https://github.com/tchitete1/Recap/archive/master.zip)
2. Open a new terminal window in the directory where the archive was downloaded
3. Unzip the archive using the following command to obtain the ```Recap-master``` directory:
```
unzip Recap-master.zip
```
4. Change into the ```Recap-master``` directory by executing the following command:
```
cd Recap-master
```

### Compilation

* To compile ```recap```, enter the following:
```
make recap
```
or
```
make
```

### Execution

* To execute ```recap```, execute the following:
```
./recap <disk image>.raw
```
where ```disk image``` is the ```card``` disk image, located in the ```Recap-master``` directory, with which, Recap will execute

### Restoration

* To restore the ```Recap-master``` directory back to its original state, execute the following command:
```
make clean
```

## Author

Tanaka Chitete
* [Linkedin](https://www.linkedin.com/in/tanaka-chitete/)

## Acknowledgments

* Thank you to [DomPizzie](https://github.com/DomPizzie) for the [template](https://gist.github.com/DomPizzie/7a5ff55ffa9081f2de27c315f5018afc)
