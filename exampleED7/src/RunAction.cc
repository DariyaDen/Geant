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
#include "G4SystemOfUnits.hh"

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
  for ( G4int i=0; i<10; ++i) {
    std::ostringstream os;
    os << i;
    G4String hname = "Layer";
    hname += os.str();
    G4String htitle = "Edep [MeV] in layer ";
    htitle += os.str();
    htitle += " in EmCalorimeter";
    analysisManager->CreateH1(hname, htitle, 100, 0., 800);
  }

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
