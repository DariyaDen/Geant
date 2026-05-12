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
// $Id: ActionInitialization.hh 68058 2013-03-13 14:47:43Z gcosmo $
//
/// \file BiasingOperator.hh
/// \brief Definition of the BiasingOperator class

#ifndef BiasingOperator_h
#define BiasingOperator_h 1

#include "G4VBiasingOperator.hh"

#include "BiasingOperationSplitAndKill.hh"

namespace ED
{

/// Biasing operator class.

class BiasingOperator : public G4VBiasingOperator
{
  public:
    BiasingOperator();
    ~BiasingOperator() override;

  private:
    // --------------------------
    // Mandatory from base class:
    // --------------------------
    // Used for splitting/killing:
    G4VBiasingOperation* ProposeNonPhysicsBiasingOperation(
      const G4Track* track, const G4BiasingProcessInterface* callingProcess) override;

    // Used for cross-section change:
    G4VBiasingOperation* ProposeOccurenceBiasingOperation(
      const G4Track* track, const G4BiasingProcessInterface* callingProcess) override;

    // Not used in this exercise:
    G4VBiasingOperation* ProposeFinalStateBiasingOperation(
      const G4Track*, const G4BiasingProcessInterface*) override {return nullptr;}

  private:
    BiasingOperationSplitAndKill* fSplitAndKillOperation = nullptr;
};

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif


