//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id$
//
/// \file RunAction.cc
/// \brief Implementation of the RunAction class

#include "RunAction.hh"

#include "G4AnalysisManager.hh"
#include "G4Run.hh"

namespace ED
{

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::RunAction()
{
  // Create analysis manager
  auto analysisManager = G4AnalysisManager::Instance();
  analysisManager->SetVerboseLevel(1);

  // Creating histograms per layer
  //
  analysisManager->CreateH1("Layer0", "Edep [MeV] in layer 0", 100, 0., 800);
  analysisManager->CreateH1("Layer1",  "Edep [MeV] in layer 1",  100, 0., 800);
  analysisManager->CreateH1("Layer2",  "Edep [MeV] in layer 2",  100, 0., 800);
  analysisManager->CreateH1("Layer3",  "Edep [MeV] in layer 3",  100, 0., 800);
  analysisManager->CreateH1("Layer4",  "Edep [MeV] in layer 4",  100, 0., 800);
  analysisManager->CreateH1("Layer5",  "Edep [MeV] in layer 5",  100, 0., 800);
  analysisManager->CreateH1("Layer6",  "Edep [MeV] in layer 6",  100, 0., 800);
  analysisManager->CreateH1("Layer7",  "Edep [MeV] in layer 7",  100, 0., 800);
  analysisManager->CreateH1("Layer8",  "Edep [MeV] in layer 8",  100, 0., 800);
  analysisManager->CreateH1("Layer9",  "Edep [MeV] in layer 9",  100, 0., 800);

  // Alternative code with a loop over layer number and generating the
  // name & title for each layer
  // for ( G4int i=0; i<10; ++i) {
  //   std::ostringstream os;
  //   os << i;
  //   G4String hname = "Layer";
  //   hname += os.str();
  //   G4String htitle = "Edep [MeV] in layer ";
  //   htitle += os.str();
  //   htitle += " in EmCalorimeter";
  //   analysisManager->CreateH1(hname, htitle, 100, 0., 800);
  // }

  // Creating ntuples
  //
  // ntuple id = 0
  analysisManager->CreateNtuple("Chamber1", "Chamber 1 hits");
  analysisManager->CreateNtupleIColumn("Layer");   // column id = 0
  analysisManager->CreateNtupleDColumn("Xpos");    // column id = 1
  analysisManager->CreateNtupleDColumn("Ypos");    // column id = 2
  analysisManager->CreateNtupleDColumn("Zpos");    // column id = 3
  analysisManager->FinishNtuple();
  // ntuple id = 1
  analysisManager->CreateNtuple("Chamber2", "Chamber 2 hits");
  analysisManager->CreateNtupleIColumn("Layer");   // column id = 0
  analysisManager->CreateNtupleDColumn("Xpos");    // column id = 1
  analysisManager->CreateNtupleDColumn("Ypos");    // column id = 2
  analysisManager->CreateNtupleDColumn("Zpos");    // column id = 3
  analysisManager->FinishNtuple();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::~RunAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::BeginOfRunAction(const G4Run* /*run*/)
{
  // Get analysis manager
  auto analysisManager = G4AnalysisManager::Instance();

  // Open an output file
  G4String fileName = "ED.root";
  analysisManager->OpenFile(fileName);
  G4cout << "Using " << analysisManager->GetType() << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::EndOfRunAction(const G4Run* /*run*/)
{
  // save histograms
  //
  auto analysisManager = G4AnalysisManager::Instance();
  analysisManager->Write();
  analysisManager->CloseFile();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

}
