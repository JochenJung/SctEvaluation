/** Generated by YAKINDU Statechart Tools code generator. */

#ifndef SCTOPERATIONEVALUATIONUNIT_H_
#define SCTOPERATIONEVALUATIONUNIT_H_

/*!
Forward declaration for the SctOperationEvaluationUnit state machine.
*/
class SctOperationEvaluationUnit;


#include <deque>
#include "../src-lib/sc_types.h"
#include "../src-lib/sc_statemachine.h"

/*! \file
Header of the state machine 'SctOperationEvaluation'.
*/


#ifndef SCT_EVENTS_SCTOPERATIONEVALUATION_H
#define SCT_EVENTS_SCTOPERATIONEVALUATION_H
#ifndef SC_INVALID_EVENT_VALUE
#define SC_INVALID_EVENT_VALUE 0
#endif

namespace sctoperationevaluation_events
{
typedef enum  {
	invalid_event = SC_INVALID_EVENT_VALUE,
	Evaluation_inEvent
} SctOperationEvaluationUnitEventName;

class SctEvent
{
	public:
		SctEvent(SctOperationEvaluationUnitEventName name) : name(name){}
		virtual ~SctEvent(){}
		const SctOperationEvaluationUnitEventName name;
		
};
		
template <typename T>
class TypedSctEvent : public SctEvent
{
	public:
		TypedSctEvent(SctOperationEvaluationUnitEventName name, T value) :
			SctEvent(name),
			value(value)
			{}
		virtual ~TypedSctEvent(){}
		const T value;
};

class SctEvent_Evaluation_inEvent : public TypedSctEvent<sc_string>
{
	public:
		SctEvent_Evaluation_inEvent(SctOperationEvaluationUnitEventName name, sc_string value) :
			TypedSctEvent(name, value) {};
};

}
#endif /* SCT_EVENTS_SCTOPERATIONEVALUATION_H */


/*! Define indices of states in the StateConfVector */
#define SCVI_MAIN_REGION_STATEA 0
#define SCVI_MAIN_REGION_STATEB 0


class SctOperationEvaluationUnit : public sc::StatemachineInterface
{
	public:
		SctOperationEvaluationUnit();
		
		virtual ~SctOperationEvaluationUnit();
		
		/*! Enumeration of all states */ 
		typedef enum
		{
			SctOperationEvaluation_last_state,
			main_region_StateA,
			main_region_StateB
		} SctOperationEvaluationStates;
					
		static const sc_integer numStates = 2;
		
		
		//! Inner class for evaluation interface scope.
		class Evaluation
		{
			public:
				Evaluation(SctOperationEvaluationUnit* parent);
				
				/*! Raises the in event 'inEvent' that is defined in the interface scope 'evaluation'. */
				void raiseInEvent(sc_string value);
				
				
				
				
				//! Inner class for evaluation interface scope operation callbacks.
				class OperationCallback
				{
					public:
						virtual ~OperationCallback() = 0;
						
						virtual sc_boolean exampleOperation(sc_string example) = 0;
						
						
				};
				
				/*! Set the working instance of the operation callback interface 'OperationCallback'. */
				void setOperationCallback(OperationCallback* operationCallback);
				
				
			private:
				friend class SctOperationEvaluationUnit;
				
				/*! Raises the in event 'inEvent' that is defined in the interface scope 'evaluation'. */
				void internal_raiseInEvent(sc_string value);
				sc_boolean inEvent_raised;
				sc_string inEvent_value;
				void dispatch_event(sctoperationevaluation_events::SctEvent * event);
				
				SctOperationEvaluationUnit* parent;
				
				
				
				OperationCallback* ifaceEvaluationOperationCallback;
				
				
		};
		
		/*! Returns an instance of the interface class 'Evaluation'. */
		Evaluation* evaluation();
		
		
		/*
		 * Functions inherited from StatemachineInterface
		 */
		virtual void enter();
		
		virtual void exit();
		
		/*!
		 * Checks if the state machine is active (until 2.4.1 this method was used for states).
		 * A state machine is active if it has been entered. It is inactive if it has not been entered at all or if it has been exited.
		 */
		virtual sc_boolean isActive() const;
		
		
		/*!
		* Checks if all active states are final. 
		* If there are no active states then the state machine is considered being inactive. In this case this method returns false.
		*/
		virtual sc_boolean isFinal() const;
		
		/*! 
		 * Checks if member of the state machine must be set. For example an operation callback.
		 */
		sc_boolean check();
		
		
		/*! Checks if the specified state is active (until 2.4.1 the used method for states was calles isActive()). */
		sc_boolean isStateActive(SctOperationEvaluationStates state) const;
		
		
		
	protected:
		
		
	private:
		SctOperationEvaluationUnit(const SctOperationEvaluationUnit &rhs);
		SctOperationEvaluationUnit& operator=(const SctOperationEvaluationUnit&);
		
		
		//! the maximum number of orthogonal states defines the dimension of the state configuration vector.
		static const sc_ushort maxOrthogonalStates = 1;
		
		
		
		SctOperationEvaluationStates stateConfVector[maxOrthogonalStates];
		
		
		Evaluation ifaceEvaluation;
		
		
		sc_boolean isExecuting;
		
		
		// prototypes of all internal functions
		
		void enseq_main_region_StateA_default();
		void enseq_main_region_StateB_default();
		void enseq_main_region_default();
		void exseq_main_region_StateA();
		void exseq_main_region_StateB();
		void exseq_main_region();
		void react_main_region__entry_Default();
		sc_integer react(const sc_integer transitioned_before);
		sc_integer main_region_StateA_react(const sc_integer transitioned_before);
		sc_integer main_region_StateB_react(const sc_integer transitioned_before);
		void clearInEvents();
		void microStep();
		void runCycle();
		
		
		sctoperationevaluation_events::SctEvent* getNextEvent();
		void dispatch_event(sctoperationevaluation_events::SctEvent * event);
		std::deque<sctoperationevaluation_events::SctEvent*> inEventQueue;
		
		
};


inline SctOperationEvaluationUnit::Evaluation::OperationCallback::~OperationCallback() {}


#endif /* SCTOPERATIONEVALUATIONUNIT_H_ */
